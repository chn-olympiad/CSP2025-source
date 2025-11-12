#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0,n,a[1000001],f[5001][5001],mod=998244353,vis[1000001];
void plzh(){
	for(int i=1;i<=5000;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i) f[i][j]=1;
			else f[i][j]=f[i-1][j]+f[i-1][j-1];
		}
	}
}
void dfs(int xb,int step,int sum,int maxx){
	if(step>=3&&sum>maxx*2&&vis[xb-1]==1) ans++;
	ans%=mod;
//	cout<<ans<<" "<<xb<<" "<<step<<" "<<sum<<" "<<maxx<<'\n';
	if(xb>n) return;
	vis[xb]=1; 
	dfs(xb+1,step+1,sum+a[xb],max(maxx,a[xb]));
	vis[xb]=0;
	dfs(xb+1,step,sum,maxx);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		plzh();
		for(int i=3;i<=n;i++){
			ans=ans+f[n][i];
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
} 
