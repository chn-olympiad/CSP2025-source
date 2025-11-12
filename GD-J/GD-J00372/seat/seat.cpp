#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
//定义
int n,m,a1;//a1是小R的成绩 
int score[101];//成绩数组 
int seat[11][11];//座位二维数组 
//排序函数
int fun(int a,int b){
	return a>b;
} 
int main(){
	//文件操作
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	//输入
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	} 
	a1=score[1];//记录小R的成绩 
	//对成绩进行排序
	sort(score+1,score+n*m+1,fun);
	//将座位按照成绩的高低排序
	for(int i=1;i<=m;i++){
		//如果当前列数是奇数
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				seat[j][i]=score[(i-1)*n+j];
			}
		}else{//如果当前列数是偶数 
			for(int j=n;j>=1;j--){
				seat[j][i]=score[(i-1)*n+n+1-j];
			}
		}
	} 
	//在座位表中查找成绩
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==a1){
				cout<<j<<" "<<i;
			}
		}
	}
	//文件操作
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

