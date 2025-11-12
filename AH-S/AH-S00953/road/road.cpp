#include <bits/stdc++.h>
using namespace std;

struct edge{
	int to;
	long long v;
};
	
int n,m,k;
bool flag=1,vis[10005],vis2[15];
vector <edge> v[1000005];
long long c[15];
long long coss[15][10005];
long long ans=-1;

void dfs(int st,int num,long long co){
	if(num==n){
		if(ans==-1) ans=co;
		else ans=min(co,ans);
		return ;
	}
	for(int i=0;i<v[st].size();i++){
		int to=v[st][i].to;long long va=v[st][i].v;
		if(vis[to]==1) continue ;
		vis[to]=1;
		dfs(to,num+1,co+va);
		dfs(st,num+1,co+va);
		vis[to]=0;
	}
	if(flag==1) return ;
	for(int i=1;i<=k;i++){
		int coo=0;
		if(vis2[i]==0) coo=c[i];
		for(int j=1;j<=n;j++){
			if(vis[j]==1) continue ;
			vis[j]=1;
			if(vis2[i]==0){
				vis2[i]=1;
				dfs(j,num+1,co+coo+coss[i][j]+coss[i][st]);
				dfs(st,num+1,co+coo+coss[i][j]+coss[i][st]);
				vis2[i]=0;
			}
			else{
				dfs(j,num+1,co+coo+coss[i][j]);
				dfs(st,num+1,co+coo+coss[i][j]+coss[i][st]);
			}
			vis[j]=0;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,vv;
		long long w;
		scanf("%d%d%lld",&u,&vv,&w);
		v[u].push_back({vv,w});
		v[vv].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		flag=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&coss[i][j]);
			if(coss[i][j]==0) flag=1;
		}
		if(c[i]!=0) flag=0;
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(coss[j][i]==0){
					for(int l=1;l<=n;l++){
						if(l==i) continue ;
						v[i].push_back({l,coss[j][l]});
						v[l].push_back({i,coss[j][l]});
					}
				}
			}
		}
	}
	vis[1]=1;
	dfs(1,1,0);
	printf("%lld",ans);
	return 0;
}
