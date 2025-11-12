#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

#if 0
#define Logi(fmt, ...); {printf("line: %d   ", __LINE__); printf(fmt, ##__VA_ARGS__); printf("\r\n");}
#else
#define Logi(fmt, ...); {}
#endif

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAX_DATA_NUMBER = 100005;  // 10的 5 次方 
int gTheDataNumber = -1;  // 这是数据个数 
int  gTheStudentNumber = -1; // 这是这组数据的学生人数 
int gClubMaxNumber = -1; // 这是一个club 最多能收几个学生

int gStudentAll = 0;  //  学生满意度； 

int gClub[3]; 


typedef struct {
	int a[3];  // 分别是对三个部门的好感度 
	int max1;
	int max2;
	int max3;
	
	int maxPos1;
	int maxPos2;
	int maxPos3;
	
	int isUsed;  // 如果用过就是 1， 没用过就是 0 
	
	void findMax() {
		
		isUsed = 0;
		
		int i;
		int rst = -1;
		int max = -1;
		int nowPos = -1;
		int noPos = -1;
		int noPos2 = -1;
		for(i = 0; i < 3; i++) {
			rst = a[i];
			nowPos = i;
			if(rst >  max) {
				max = rst;
				noPos = i;
			}
		}
		
		max1 = max;
		maxPos1 = noPos;
		
		rst = -1;
		max = -1;
		nowPos = -1;
		//noPos = -1;  // 这是要保留的 
		noPos2 = -1;
		
		for(i = 0; i < 3; i++) {
			
			if(i == noPos) {
				continue;
			}
			
			rst = a[i];
			nowPos = i;
			if(rst >  max) {
				max = rst;
				noPos2 = i;
			}
		}
		
		max2 = max;
		maxPos2 = noPos2;
		
		rst = -1;
		max = -1;
		nowPos = -1;
		//noPos = -1;  // 这是要保留的 
		//noPos2 = -1;  同上 
		
		int lastPos = -1;
		
		for(i = 0; i < 3; i++) {
			
			if(i == noPos) {
				continue;
			}
			
			if(i == noPos2) {
				continue;
			}
			
			rst = a[i];
			nowPos = i;
			if(rst >  max) {
				max = rst;
				lastPos = i;
			}
		}
		
		max3 = max;
		maxPos3 = lastPos;
	}
}S_STUDENT; 


S_STUDENT gStudent[MAX_DATA_NUMBER]; 

void printStruct(S_STUDENT a) {
	int i;
	for(i = 0; i < 3; i++) {
		printf("%d ", a.a[i]);
	}
	
	printf("%d %d %d %d %d %d\r\n \r\n", a.max1, a.max2, a.max3, a.maxPos1, a.maxPos2, a.maxPos3);
}  

void printStudent() {
	int i;
	
	Logi("gStudnet:")
	
	for(i = 0; i < gTheStudentNumber; i++) {
		printStruct(gStudent[i]);
	}
}

void init() {
	// 输入
	
	cin >> gTheDataNumber;
}

bool compare1(S_STUDENT a, S_STUDENT b) {
	if(a.max1 > b.max1) {
		return true;
	} else {
		return false;
	}
} 

void opMaxA() {
	int i;
	
	sort(gStudent, gStudent + gTheStudentNumber, compare1);
	
	
	
	for(i = 0; i < gTheStudentNumber; i++) {
		int curPos = gStudent[i].maxPos1;
		int max1 = gStudent[i].max1;
		
		if(gClub[curPos] < gClubMaxNumber) {
			gClub[curPos]++;
			gStudent[i].isUsed = 1;
			gStudentAll = gStudentAll + max1; 
		}
	}
}

bool compare2(S_STUDENT a, S_STUDENT b) {
	if(a.max2 > b.max2) {
		return true;
	} else {
		return false;
	}
}

void opMax2A() {
	int i;
	
	sort(gStudent, gStudent + gTheStudentNumber, compare2);
	
	
	for(i = 0; i < gTheStudentNumber; i++) {
		int curPos = gStudent[i].maxPos2;
		int max1 = gStudent[i].max2;
		
		if(gClub[curPos] < gClubMaxNumber  && gStudent[i].isUsed <= 0) {
			gClub[curPos]++;
			gStudent[i].isUsed = 1;
			gStudentAll = gStudentAll + max1; 
		}
	}
}

void opMax3A() {
	int i;
	
	for(i = 0; i < gTheStudentNumber; i++) {
		int curPos = gStudent[i].maxPos3;
		int max3 = gStudent[i].max3;
		
		if(gClub[curPos] < gClubMaxNumber  && gStudent[i].isUsed <= 0) {
			gClub[curPos]++;
			gStudent[i].isUsed = 1;
			gStudentAll = gStudentAll + max3; 
		}
	}
}

int maxAll = -1;

bool runStep(int targetPos) {
	if(gClub[targetPos] >= gClubMaxNumber) {
		return false;
	}
	
	return true;
}


void dfs(int student) {
	int i;
	
	if(student >= gTheStudentNumber) {
		
		if(gStudentAll > maxAll) {
			maxAll = gStudentAll;
		}
		
		return;
	}
	
	for(i = 0; i < 3; i++) {
		if(runStep(i)) {
			gStudentAll = gStudentAll + gStudent[student].a[i];
			dfs(student + 1);
			gStudentAll = gStudentAll - gStudent[student].a[i];
		}
		
	}
}



void startRun() {
	int i;
	int j;
	
	for(i = 0; i < gTheDataNumber; i++) {
		cin >> gTheStudentNumber;
		gClubMaxNumber = gTheStudentNumber / 2; 
		
		gClub[0] = 0;
		gClub[1] = 0;
		gClub[2] = 0;
		
		maxAll = 0;
		
		gStudentAll = 0;
		
		for(j = 0; j < gTheStudentNumber; j++) {
			cin >> gStudent[j].a[0] >> gStudent[j].a[1] >> gStudent[j].a[2];
			gStudent[j].findMax();
		}
		
		//printStudent();  //      todo
		
		#if 0
		if(1 == 1) {
			Logi("NEW:");
			
			sort(gStudent, gStudent + gTheStudentNumber, compare1);
			printStudent();  //      todo
			
			Logi("end\r\n");
			
		}
		#endif
		
		if(gTheStudentNumber <= 200) {
			dfs(0);
			
			cout << maxAll << endl;
			
			continue;
			
		} 
		
		opMaxA();
		opMax2A();
		opMax3A();
		
		cout << gStudentAll << endl;
		
	}
	
}

void test() {
	S_STUDENT a;
	a.a[0] = 2;
	a.a[1] = 1;
	a.a[2] = 3;
	
	a.findMax();
	
	printStruct(a);

}

int main(int argc, char** argv) {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	init();
	startRun();
	
	//test();
	
	return 0;
}
