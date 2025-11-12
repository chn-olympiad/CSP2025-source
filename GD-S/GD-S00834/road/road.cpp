#include <iostream>
#include <queue> 
#include <vector>

using namespace std;
#if 0
#define Logi(fmt, ...); {printf("line: %d   ", __LINE__); printf(fmt, ##__VA_ARGS__); printf("\r\n");}
#else
#define Logi(fmt, ...); {}
#endif
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gOrgPointNumber = -1;  // 原来城市数量 
int gEdgeNumber = -1;  // 原来线的数量 
int gNewPointNumber = -1;  // 新规划的数量 

int gAllPointNumber = -1;

const int gMAX_POINT_NUMBER = 10005;  // 10的 5 次方 

int gEdge[gMAX_POINT_NUMBER][gMAX_POINT_NUMBER];
int gEdge2Add[gMAX_POINT_NUMBER][gMAX_POINT_NUMBER];

typedef struct {
	int min;
	int fromPoint;
	
}S_POINT;

S_POINT gDp[gMAX_POINT_NUMBER];

int gIsHave[gMAX_POINT_NUMBER];
queue<int> gQ;

int gIsVisitedNew[gMAX_POINT_NUMBER];
int gNewBig[gMAX_POINT_NUMBER];

 

void init() {
	
	
	Logi("???");
	int i;
	int j;
	Logi("???");
	
	for(i = 0; i < gMAX_POINT_NUMBER - 1; i++) {
		for(j = 0; j < gMAX_POINT_NUMBER - 1; j++) {
			gEdge[i][j] = -1;
		}
	}
	Logi("??? %d", gEdge[i][j]);
	Logi("???");
	
	cin >> gOrgPointNumber >> gEdgeNumber >> gNewPointNumber; 
	
	gAllPointNumber = gOrgPointNumber +gNewPointNumber;
	
	for(i =0 ; i < gEdgeNumber; i++) {
		int u;
		int v;
		int eVal;
		
		cin >> u >> v >> eVal;
		
		gEdge[u][v] = eVal;
		gEdge[v][u] = eVal;
		
		Logi("eval = %d" , eVal);
		
	}
	
	Logi("???");
	 
	for(i = 0; i < gNewPointNumber; i++) {
		
		int u = gOrgPointNumber + i + 1;
		
		Logi("u = %d", u);
		
		int temp1;
		cin >> temp1;
		
		gIsVisitedNew[u] = 0;
		gNewBig[u] = temp1;
		
		for(j = 1; j <= gOrgPointNumber; j++) {
			int temp2;
			cin >> temp2;
			gEdge[u][j] = temp2;
			gEdge[j][u] = temp2;
			
			Logi("%d", gEdge[u][j]);
		}
	}
	Logi("???");
	
	for(i = 0; i <gMAX_POINT_NUMBER; i++) {
		gDp[i].min = -1;
		gDp[i].fromPoint = 0;
	}
	
	
	for(i = 0; i < gMAX_POINT_NUMBER; i++) {
		gIsHave[i] = -1;
	}
	
	
	for(i = 0; i < gMAX_POINT_NUMBER - 1; i++) {
		for(j = 0; j < gMAX_POINT_NUMBER - 1; j++) {
			gEdge2Add[i][j] = -1;
		}
	}
	
}

bool new2Point(int u, int v) {  // 从 u 更新向 v 
	
	int number = gEdge[u][v];
	
	if(number <0) {
		return false;
	}
	
	
	
	int temp1 = gDp[u].min + number;
	
	if(gIsVisitedNew[u] <= 0 ) {
		temp1 + gNewBig[u];
		gIsVisitedNew[u] = 1;
	}
	
	if(gDp[u].min < 0) {
		return false;
	}
	
	int temp2 = gDp[v].min;
	
	if(temp1 < temp2 || temp2 < 0) {
		gDp[v].min = temp1;
		gDp[v].fromPoint = u;
		return true;
	}
	
	return false;
}



void pointNew(int pos) {   // 点的更新 
	int i;
	
	for(i = 1; i <= gAllPointNumber; i++) {
		if(gEdge[pos][i] >= 0) {
			if(new2Point(pos, i) ) {
				if(gIsHave[i] <= 0) {
					gQ.push(i);
					gIsHave[i] = 1;
				}
			}
		}
	} 
	
	
}

void printDp() {
	int i;
	for(i = 1; i <= gAllPointNumber; i++) {
		printf("min = %d from = %d \r\n", gDp[i].min, gDp[i].fromPoint);
	}
}

typedef struct {
	int to;
	int val;
}S_EDGE;



void startRun() {
	int i;
	pointNew(1);
	gIsHave[1] = 1;
	gQ.push(1);
	gDp[1].min = 0;
	
	while(!gQ.empty()) {
		int curPos = gQ.front();
		gQ.pop();
		gIsHave[curPos] = -1;
		
		pointNew(curPos);
	}
}



int main(int argc, char** argv) {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdin);
	
	init();
	
	startRun();
	//printDp();
	
	int max = 0;
	int i;
	for(i = 1; i <= gAllPointNumber; i++) {
		if(gDp[i].min > max) {
			max = gDp[i].min;
		}
		
	}
		cout << max << endl;
	
	
	return 0;
}
