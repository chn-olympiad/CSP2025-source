#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
int a[10005];
long long cnt;
void dfs(int id,int sum,int maxa,long long ans,bool f){
	if(sum>maxa*2&&ans>=3&&f==1){
		cnt++;
		cnt%=998244353;
	} 
	if(id>n){
		return;
	}
	dfs(id+1,sum+a[id],max(maxa,a[id]),ans+1,1);
	dfs(id+1,sum,maxa,ans,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0,0);
	cout<<cnt;
	return 0;
}
