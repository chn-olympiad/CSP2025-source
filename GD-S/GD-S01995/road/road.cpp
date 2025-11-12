#include<bits/stdc++.h>
using namespace std;
const int N=10010,INF=0x3f3f3f3f;
long long n,m,k,g[N][N],x[N][N],use[N],num[N],v[N],lnum,zh,ans=INF,maxn=0;
void dfs(int f){
	if(f>n){
		zh=0;
		for(int i=2;i<=n;i++){
			lnum=INF;
			for(int j=1;j<=k;j++){
				lnum=min(min(lnum,g[num[i-1]][num[i]]),x[j][num[i-1]]+x[j][num[i]]+v[j]);
			}
			zh+=lnum;
		}
		ans=min(ans,zh);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(use[i]==0){
			num[f]=i;
			use[i]=1;
			dfs(f+1);
			use[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(g,INF,sizeof g);
	memset(num,INF,sizeof num);
	for(int i=1;i<=m;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		g[a][b]=g[b][a]=min(g[a][b],c);
		maxn=max(maxn,c);
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++)
			cin>>x[i][j];
	}
	if(maxn==0){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
