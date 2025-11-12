#include<bits/stdc++.h>
using namespace std;
int n=0;//边数
int a[5005]={}; //边
long long situations_n=0; 
void dfs(int A,int max_n,int plus_n,int zz){//A:直至上次共多少条边；max_n，plus_n:直至上次 ;zz：本次 
if(zz>n)return;
	if(A+1>=3&&2*max(max_n,a[zz])<plus_n+a[zz]){
		situations_n=(situations_n+1)%998244353;//若选择本次，直至本次是否能形成图形
	}
	dfs(A+1,max(max_n,a[zz]),plus_n+a[zz],zz+1);//选择本次 
	dfs(A,max_n,plus_n,zz+1); //不选本次 
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<situations_n/2;
}
