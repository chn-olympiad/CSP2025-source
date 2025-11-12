/*
记下小r的成绩
从大到小排序

开始时方向朝下
用if判定走 

撞到下底:
	先左转
	再直走
	再左转
上底:
	先右转
	再直走
	再右转

遇到小r的成绩 
输出 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x=1,y=1,fx=0;
int a[105],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<y<<" "<<x;
			return 0;
		}
		if(fx==0){
			if(x+1<=n){
				x++;
			}
			else{
				y++;
				fx=1;
			}
		}
		else{
			if(x-1>0){
				x--;
			}
			else{
				y++;
				fx=0;
			}
		}
	}
	if(a[n*m]==r){
		cout<<m<<" "<<n;
		return 0;
	}
	return 0;
}