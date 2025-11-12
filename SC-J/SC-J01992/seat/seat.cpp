#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[101];
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int mb=a[1];
	sort(a+1,a+1+n*m,cmp);
	int t=0;
	int x=0,y=1;
	int s=0;
	int flag=1;
	for(int i=1;i<=n*m;i++){
		t++;
		s++;
		if(t==n+1){
			y++;
			t%=n;
			flag++;
			flag%=2;
		}else if(flag==1){
			x++;
		}else if(flag==0){
			x--;
		}
		if(a[s]==mb){
			cout<<y<<" "<<x;
			return 0;
		}
	}
	return 0;
}
/*
100% 
O(2*n*m) 200
给成绩排序
找到小R在第几名
循环依次排位置 直到排到小R后 输出 
3 3
94 95 96 97 98 99 100 93 92
*/