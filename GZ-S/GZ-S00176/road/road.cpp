//GZ-S00176 贵阳市第一中学 张轩睿 
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+50,M=2e6;
int n,m,k;
int K_road[15][N];
int cost[15];int father[N];
int finans=0x3f3f3f3f;
int find(int x){
	return father[x]==x?x:father[x]=find(father[x]); 
} 
struct Edge_Node{
	int from,to,wei;
	bool operator<(const Edge_Node& node)const{
		return wei<node.wei;
	}
};
vector<Edge_Node>edge;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		edge.push_back({u,v,w});
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&cost[i]);
		for (int j=1;j<=n;j++)
			scanf("%d",&K_road[i][j]);
	}
	for (int i=0;i<(1<<k);i++){
		vector<Edge_Node>now_edge=edge;
		int n_num=n,m_num=m;int ans=0;
		for (int j=1;j<=k;j++)
			if (i&(1<<(j-1))){
				n_num++;m_num+=n;ans+=cost[j];
				for (int pos=1;pos<=n;pos++)
					 now_edge.push_back({n_num,pos,K_road[j][pos]});
			}
		for (int i=1;i<=n_num;i++)father[i]=i;
		sort(now_edge.begin(),now_edge.end());
		int edge_num=0;
		for (int i=0;i<(int)now_edge.size();i++){
			int fx=find(now_edge[i].from),fy=find(now_edge[i].to);
			if (fx==fy)continue;
			father[fx]=fy;
			edge_num++;ans+=now_edge[i].wei;
			if (edge_num==n_num-1)break; 
		}
		finans=min(finans,ans);
	}
	printf("%d",finans);
	return 0;
}
