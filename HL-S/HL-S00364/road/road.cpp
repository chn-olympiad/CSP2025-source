#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=1E4+10;
struct edge{
	int idx;
	int dis;
};
bool operator<(edge a,edge b){
	return a.dis>b.dis;
}
priority_queue<edge>g[MAXN];
bool vis[MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push({v,w});
		g[v].push({u,w});
	}
	if(!k){
		vis[1]=true;
		long long ans=0;
		for(int i=1;i<n;i++){
			int minDis=2E9,pos;
			for(int j=1;j<=n;j++){
				if(vis[j]){
					while(!g[j].empty()&&vis[g[j].top().idx]){
						g[j].pop();
					}
					if(!g[j].empty()&&g[j].top().dis<minDis){
						minDis=g[j].top().dis,pos=j;
					}
				}
			}
			ans+=minDis;
			vis[g[pos].top().idx]=true;
		}
		printf("%lld\n",ans);
	}else{
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}