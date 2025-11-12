#include<bits/stdc++.h>
using namespace std;
int a[1000001],n,m,g[1001][1001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int res=a[1];
	sort(a+1,a+1+n*m,cmp); 
	int flag=1,idx=0;
	for(int i=1;i<=m;i++){
		if(flag==1){
			for(int j=1;j<=n;j++){
				idx++;
				if(a[idx]==res){
					printf("%d %d",i,j);
					return 0;
				}
//					g[i][j]=a[idx];
			}
		}else{
			for(int j=n;j>=1;j--){
				idx++;
				if(a[idx]==res){
					printf("%d %d",i,j);
					return 0;
				}
//					g[i][j]=a[idx];
			}
		}
		flag=flag^1;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)printf("%d ",g[i][j]);
//		puts("");
//	}
	return 0;
}
/*
不是这是什么T2
太神秘了，感觉不如去年，不会分数线涨上300吧/bx 
考验选手模拟能力 
我初一时T2可不是这个难度（ 

好惊险，幸好回来后多测了几组，发现有1车bug，再也不半场开香槟了。 

最后五分钟发现 n m写反了，太惊险了 
7 2
9 8 6 5 4 3 2 1 7 10 11 12 13 14
*/