#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+100;
int dp[4][N]={0};
int v[4]={};
int t;
int n;
struct A{
	int a1;
	int a2;
	int a3;
};
A a[N],nm;
int an=-99;
void f(int x,int y,int xy){
	for(int i=1;i<=3;i++)
		if(v[i]>n/2)
			return;
			
			
	if(x==n){
		an=max(an,xy);
		cout<< xy << endl;
		return;
	}
	
	
	
	v[y]++;
	f(x+1,y,xy+a[x+1].a1);
	v[y]--;
	if(y+1<=3 && !v[y+1]){
		v[y+1]++;
		if(y+1==2)
			f(x+1,y+1,xy+a[x+1].a2);
		else if(y+1==3)
			f(x+1,y+1,xy+a[x+1].a3);
		v[y+1]--;	
	}
	if(y+2<=3 && !v[y+2]){
		v[y+2]++;
		f(x+1,y+2,xy+a[x+1].a3);
		v[y+2]--;
	}
	if(y-1>0 && !v[y-1]){
		v[y-1]++;
		if(y-1==2)
			f(x+1,y-1,xy+a[x+1].a2);
		else
			f(x+1,y-1,xy+a[x+1].a1);
		v[y-1]--;	
	}
	if(y-2>0 && !v[y-2]){
		v[1]++;
		f(x+1,y-2,xy+a[x+1].a1);
		v[1]--;	
	}
	for(int i=1;i<=3;i++)
			v[i]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		an=-99;
		for(int i=1;i<=3;i++)
			v[i]=0;
		v[1]=1;
		f(1,1,a[1].a1);
		v[1]=0;
		v[2]=1;
		f(1,2,a[1].a2);
		v[2]=0;
		v[3]=1;
		f(1,3,a[1].a3);
		v[3]=0;
		cout<< an << endl;
	}
	return 0;
}
