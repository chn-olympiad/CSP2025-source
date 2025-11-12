#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
int f[N],a[K][N],ff[K][N];
ll ans=1e18+7,e[N][N],dp[N];
//struct node{
//	int u,v;
//	ll w;
//} rd[M];
//bool cmp(node a,node b){
//	return a.w<b.w;
//}
int fd(int x){
	if(x==f[x]) return x;
	return f[x]=fd(f[x]);
}
void mg(int x,int y){
	int X=fd(x),Y=fd(y);
	if(X==Y) return ;
	f[X]=Y;
}
int main(){
//	freopen("test.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		e[u][v]=e[v][u]=w;
	}
//	for(int i=1;i<=m;i++) cin>>rd[i].u>>rd[i].v>>rd[i].w;
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) cin>>a[i][j];
//	sort(rd+1,rd+1+m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[j]=j;
		for(int o=1;o<=k;o++) for(int j=0;j<=n;j++) ff[o][j]=0;
		for(int j=1;j<=n;j++){
			if(i==j||fd(i)==fd(j)) continue;
			mg(i,j);
			ll sum=1e18+7,p=0;
			for(int o=1;o<=k;o++){
				if(ff[o][0]==0){
					if(sum>a[o][0]+a[o][i]+a[o][j]){
						sum=a[o][0]+a[o][i]+a[o][j];
						p=o;
					}
				}
				else{
					if(sum>a[o][i]+a[o][j]&&ff[o][i]==0&&ff[o][j]==0) sum=a[o][i]+a[o][j];
					if(sum>a[o][i]&&ff[o][j]==1) sum=a[o][i];
					if(sum>a[o][j]&&ff[o][i]==1) sum=a[o][j];
				}
			}
			if(e[i][j]<sum&&e[i][j]!=0) dp[i]+=e[i][j];
			else{
				ff[p][0]=ff[p][i]=ff[p][j]=1;
				dp[i]+=sum;
			}
		}
	}
	for(int i=1;i<=n;i++) ans=min(ans,dp[i]);
	cout<<ans;
	return 0;
}
