#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long m,n,k,ans=N*N;
long long a[N][N],b[N][N];
int vis[N];
void dfs(long long x,long long mon,long long sum){
	if(sum==m){
		ans=min(mon,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[x][i]&&!vis[i]){
			vis[i]=1;
			dfs(i,mon+a[x][i],sum+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		long long x,y,p;
		scanf("%lld%lld%lld",&x,&y,&p);
		a[x][y]=a[y][x]=p;
	}
	for(long long i=1;i<=k;i++){
		for(long long j=0;i<=n;j++) scanf("%lld",&b[i][j]);
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans;
	return 0;
}