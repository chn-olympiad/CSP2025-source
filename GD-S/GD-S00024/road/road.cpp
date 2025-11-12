#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e4+100,M=1e6+10;

struct edge{
	int u,v,w,bh;
};

vector<edge>edges,edges_bf;
int c[N],fa[N],sz[N],a[20][N],vis[N];

bool cmp(edge a,edge b){
	return a.w < b.w;
}

int findfa(int x){
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i=1;i<N;i++)fa[i]=i;
	
	int n,m,k,edge_cnt=0;
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)sz[i]=1;
	
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges_bf.push_back({u,v,w,++edge_cnt});
	}
	
	int maxx=0,f=1;
	for (int j=1;j<=k;j++){
		cin >> c[j];
		maxx=max(maxx,c[j]);
		bool flag=0;
		for (int i=1;i<=n;i++){
			cin >> a[j][i];
			if (a[j][i]==0)f=1;
		}
		if (!flag)f=0;
	}
	
	if (maxx==0 && f){								//特殊性质 A 
		for (auto i:edges_bf)edges.push_back({i.u,i.v,i.w,i.bh});
		for (int j=1;j<=k;j++){
			for (int i=1;i<=n;i++){
				edges.push_back({j+n,i,a[j][i],++edge_cnt});
			}
		}
	}else{
		int minn=1e9;
		for (int zt=0;zt<=(1<<k)-1;zt++){			//状态压缩枚举激活的乡村 32
			for (int i=1;i<=n+k;i++){
				fa[i]=i;
				vis[i]=0;
				if (i<=n)sz[i]=1;
			}
			edges.clear();
			
			for (auto i:edges_bf)edges.push_back({i.u,i.v,i.w,i.bh});
		
			for (int j=1;j<=k;j++){
				if ((1<<(j-1))&zt){
					for (int i=1;i<=n;i++){
						edges.push_back({j+n,i,a[j][i],++edge_cnt});
					}
				}
			}
			
			sort(edges.begin(),edges.end(),cmp);
			
			int sum=0;
			for (auto i:edges){
				int u=i.u,v=i.v,w=i.w;
				if (u==0 || v==0)continue;
				if (findfa(u)!=findfa(v)){
					if (u>n && !vis[u]){
						sum+=c[u-n],vis[u]=1;
					}
					if (v>n && !vis[v]){
						sum+=c[v-n],vis[v]=1;
					}
					sz[findfa(v)]+=sz[findfa(u)];
					fa[findfa(u)]=findfa(v);
					sum+=w;
					if(sz[findfa(v)]==n){
						minn=min(sum,minn);
					}
				}
			}
		}
		cout << minn;
		return 0;
	}
	
	sort(edges.begin(),edges.end(),cmp);
	
	int sum=0;
	for (auto i:edges){
		int u=i.u,v=i.v,w=i.w;
		if (u==0 || v==0)continue;
		//cout << u << " " << v << "\n";
		if (findfa(u)!=findfa(v)){
			sz[findfa(v)]+=sz[findfa(u)];
			fa[findfa(u)]=findfa(v);
			sum+=w;
			if(sz[findfa(v)]==n){
				cout << sum;
				return 0;
			}
		}
	}
	
	
	return 0;
}
