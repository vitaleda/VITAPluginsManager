/*
 * 
 * Made by NeoLTK with xerpi draw
 * 
 */
#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <psp2/display.h>
#include <psp2/gxm.h>
#include <psp2/io/dirent.h>
#include <psp2/io/stat.h>
#include <psp2/io/fcntl.h>

#include "utils.h"
#include "draw.h"

typedef struct plugins {
	char *name;
	char *path;
	bool active;
	bool safe;
} Plugins;

typedef struct menu {
	char *title;
	void (*function)(Plugins *plugins);
} Menu;

typedef struct rightpanel {
	bool active;
	int navOffset;
	Menu *panelMenu;
} RightPanel;

typedef struct manager {
	char *version;
	int navOffset;
	bool active;
	Plugins *plugins;
	RightPanel *rightPanel;
	SceCtrlData pad;
} Manager;




#define defaultPath     ((char *) "ux0:/plugins/")
#define disablePath     ((char *) "ux0:/plugins_disabled/")
#define configsPath     ((char *) "ux0:/plugins/game.txt")
#define version     ((char *) "V0.6")

void securityCheck(Plugins *plugins);
void menuDraw(Manager *pluginsManager);
void getPlugins(Plugins plugins[]);
void getConfigs(Plugins plugins[]);
void dirPlugins(Manager *pluginsManager);
void putConfigs(Plugins plugins[]);
void controle(Manager *pluginsManager);

#endif