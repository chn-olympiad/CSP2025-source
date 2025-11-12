#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5005];
bool vis[5005]={false};
int ans=0;
void dfs(int now,int maxn,int sum,int cnt){
	if(now==n){
		if(cnt>=3&&sum>(2*maxn)){
			ans++;
		}
		return;
	}
	vis[now]=true;
	dfs(now+1,max(maxn,arr[now]),sum+arr[now],cnt+1);
	dfs(now+1,maxn,sum,cnt);
	vis[now]=false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	dfs(0,-1,0,0);
	cout<<ans;
	return 0;
}