/*
要取余 998244353 

循环枚举边数
递归计算 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[50001],s;
void dfs(int i,int d,int sm,int x,int l){
	if(i==x+1){
		if(sm>2*d){
			s++;
			s%=998244353;
		}
	}
	for(int j=l+1;j<=n;j++){
		dfs(i+1,max(d,a[j]),sm+a[j],x,j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,0,0,i,0);
	}
	cout<<s;
	return 0;
}
