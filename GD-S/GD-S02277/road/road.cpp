#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
long long dis[10005],vis[10005],c[15];
struct poi{
	int v;
	long long w;
//struct
};
vector<poi>g1[20005],g2[10005];
int n,m,k;
priority_queue<pair<long long,int> >q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i=i+1){
		int tx,ty,tz;
		scanf("%d%d%lld",&tx,&ty,&tz);
		g1[tx].push_back({ty,tz});
		g1[ty].push_back({tx,tz});
	//input
	}
	int sumc=0,ans=0;
	for(int i=1;i<=k;i=i+1){
		scanf("%d",&c[i]);
		q.push({-c[i],i+n});
		sumc=sumc+c[i];
		int tz;
		for(int j=1;j<=n;j=j+1){
			scanf("%d",&tz);
			//suma=suma+tz;
			g1[i+n].push_back({j,tz});
			//g1[j].push_back({i+n,tz});
		//build
		}
	//input-p2
	}
	dis[1]=0;
	q.push({0,1});
	while(q.empty()==false){
		pair<int,int>pr=q.top();
		int u=pr.second;
		q.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		ans=ans+dis[u];
		//printf("%d-%d.\n",u,dis[u]);
		for(int i=0;i<g1[u].size();i=i+1){
			int tv=g1[u][i].v;
			if(g1[u][i].w<dis[tv]){
				dis[tv]=g1[u][i].w;
				q.push({-dis[tv],tv});
			//add-que
			}
		//each-edge
		}
	//prim
	}
	printf("%lld\n",ans);
	return 0;
//end-- 
}
