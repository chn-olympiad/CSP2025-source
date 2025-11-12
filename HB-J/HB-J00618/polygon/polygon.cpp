#include<bits/stdc++.h>
using namespace std;
bool vis[40];
int arr[40];
int ans;int n;
int maxn(){
	int maxnn=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1&&arr[i]>=maxnn){maxnn=arr[i];}
	}
	return maxnn;
}
int ssum(){
	int ssssum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){ssssum+=arr[i];}
	}
	return ssssum;
}
int sssum(){
	int ssssum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){ssssum++;}
	}
	return ssssum;
}
bool check(){
	if(ssum()>maxn()*2&&sssum()>=3){
		return true;
	}
	return false;
}
void dfs(int now){
	if(now==n+1){
		if(check()){
			ans++;
		}
		return;
	}
	vis[now]=0;
	dfs(now+1);
	vis[now]=1;
	dfs(now+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
