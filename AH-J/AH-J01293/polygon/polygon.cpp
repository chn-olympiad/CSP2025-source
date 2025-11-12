#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005],n,ans=0;
bool vis[5005];
void dfs(int i,int s,int x,int step){
	if(s>a[x]){
		ans++;
		ans%=MOD;
	}
	if(step==x){
		return;
	}
	for(int j=i+1;j<x;j++){
		if(vis[j]){
			continue;
		}
		vis[j]=1;
		dfs(j,s+a[j],x,step+1);
		vis[j]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(0,0,i,0);
	}
	cout<<ans%MOD;
	return 0;
}
