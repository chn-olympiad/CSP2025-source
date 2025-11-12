#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int mod=998244353;
int n,a[5005],f[5005];
bool vis[5005];
ll ans;
void dfs(int u,int x){
	if(u<1)return;
	if(x<0)ans++,ans%=mod;
	for(int i=1;i<u;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(i,x-a[i]);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1); 
	for(int i=3;i<=n;i++){
		for(int j=1;j<i;j++){
			dfs(j,a[i]-a[j]);
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
