#include<bits/stdc++.h>
using namespace std;
int a[5005],cnt=0,ans=0,vis[5005],n;
void dfs(int x,int sum,int maxn){
	ans++;
	vis[x]=1;
	sum+=a[x];
	maxn=max(maxn,a[x]);
	if(ans>=3 && sum>2*maxn){
		cnt++;
		cnt=cnt%998244353;
	}
	for(int j=x+1;j<=n;j++){
		if(vis[j]==0){
			dfs(j,sum,maxn);
			vis[j]=0;
			ans--;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		memset(vis,0,sizeof(vis));
		
		dfs(i,0,0);	
	}
	cout<<cnt;
	return 0;
} 
