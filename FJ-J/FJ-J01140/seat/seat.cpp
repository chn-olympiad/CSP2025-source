//数据好小啊.....
//虽说如此,草稿还是要认真做的
//依旧询问法
//1.总体思路
// 
//Q1:思路为?
//A1:模拟.
// 
//2.大致框架
// 
//Q2:座位要怎么排?
//A2:蛇形
// 
//Q3:蛇形该怎么排?
//A3:从1,1开始,往下走,碰壁就回头且将座位位置往前移一格
// 
//Q4:碰壁就回头该怎么判断?
//A4:填完数后,如果纵坐标=0或=n + 1,那就回头
//
//Q5:"回头"要怎么实现
//A5:设置一个移动值,初始为-1(往下),每回头一次就将这个值取反一次
//
//Q6:怎么判断小R坐在哪里?
//A6:先将小R的分数存储,然后在排座位时判断这个分数是不是他的
//
//Q7:如何判断成绩高低
//A7:从大到小排序 
#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N * N],n,m,r;
int desk[N][N]; 
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);r = a[1];
	for(int i = 2;i <= n * m;i++){
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n * m + 1,cmp);
//	for(int i = 1;i <= n * m;i++){验证输入 
//		printf("%d ",a[i]);
//	}
	int nowx = 1,nowy = 1,f = 1;
	for(int i = 1;i <= n * m;i++){
	    //printf("%d %d\n",nowx,nowy);
		desk[nowx][nowy] = a[i];
		if(a[i] == r){
			printf("%d %d",nowy,nowx);
			return 0;
		}
		//printf("%d ",desk[nowx][nowy]);
		nowx += f;
		if(nowx == n + 1 || nowx == 0){
			f = -f;
			nowx += f;
			nowy++;
		}
		
		//printf("%d ",desk[nowx][nowy]);
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			printf("%d ",desk[i][j]);
//		}
//		printf("\n");
//	}
	return 0;
}

