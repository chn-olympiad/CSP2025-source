#include<bits/stdc++.h>
#define N 10010
#define M 1000010
#define K 15
using namespace std;
typedef long long ll;
int n,m,k,c[K],a[K][N],k1,k2,s1[1<<5],s2[1<<5],Log[1030];
struct Edge { int u,v,w; } edge[M],e1[1<<5][N+K],e2[1<<5][N+K];
ll v[1<<10],ans;
vector<Edge> edges;
bool cmp(Edge x,Edge y) { return x.w<y.w; }
struct DSU{
	int fa[N+K]; void init(int x) { for(int i=1;i<=x;++i) fa[i]=i; }
	int find(int x) { return fa[x]==x? fa[x]:(fa[x]=find(fa[x])); }
	void merge(int x,int y) { fa[find(x)]=find(y); }
}dsu;
int popcount(int x){
	int res;
	for(res=0;x;x&=x-1,++res);
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=10;++i) Log[1<<i-1]=i;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<(1<<k);++i) v[i]=v[i&i-1]+c[Log[i&-i]];
	sort(edge+1,edge+1+m,cmp); dsu.init(n);
	int cnt=0;
	for(int i=1;i<=m;++i){
		int fx=dsu.find(edge[i].u);
		int fy=dsu.find(edge[i].v);
		if(fx==fy) continue;
		dsu.merge(fx,fy);
		++cnt; edges.push_back(edge[i]); ans+=edge[i].w;
		if(cnt==n-1) break;
	}
	k1=k>>1, k2=k-k1;
	for(int i=0;i<(1<<k1);++i){
		cnt=0;
		for(auto j:edges) edge[++cnt]=j;
		for(int S=i;S;S&=S-1){
			int j=Log[S&-S];
			for(int x=1;x<=n;++x) edge[++cnt]=(Edge){j+n,x,a[j][x]};
		}
		sort(edge+1,edge+1+cnt,cmp); dsu.init(n+k);
		int num_edge=0,num_node=n+popcount(i);
		for(int j=1;j<=cnt;++j){
			int fx=dsu.find(edge[j].u);
			int fy=dsu.find(edge[j].v);
			if(fx==fy) continue;
			dsu.merge(fx,fy);
			++num_edge; e1[i][++s1[i]]=edge[j];
			if(num_edge==num_node-1) break;
		}
	}
	for(int i=0;i<(1<<k2);++i){
		cnt=0;
		for(auto j:edges) edge[++cnt]=j;
		for(int S=i;S;S&=S-1){
			int j=Log[S&-S]+k1;
			for(int x=1;x<=n;++x) edge[++cnt]=(Edge){j+n,x,a[j][x]};
		}
		sort(edge+1,edge+1+cnt,cmp); dsu.init(n+k);
		int num_edge=0,num_node=n+popcount(i);
		for(int j=1;j<=cnt;++j){
			int fx=dsu.find(edge[j].u);
			int fy=dsu.find(edge[j].v);
			if(fx==fy) continue;
			dsu.merge(fx,fy);
			++num_edge; e2[i][++s2[i]]=edge[j];
			if(num_edge==num_node-1) break;
		}
	}
//	for(int i=0;i<(1<<k1);++i){
//		printf("#%d: \n",i);
//		for(int j=1;j<=s1[i];++j)
//			printf("%d <--%d--> %d\n",e1[i][j].u,e1[i][j].w,e1[i][j].v);
//	}
//	for(int i=0;i<(1<<k2);++i){
//		printf("#%d: \n",i);
//		for(int j=1;j<=s2[i];++j)
//			printf("%d <--%d--> %d\n",e2[i][j].u,e2[i][j].w,e2[i][j].v);
//	}
//	puts("");
	ll now=0;
	for(int i=0;i<(1<<k1);++i){
		for(int j=0;j<(1<<k2);++j){
			now=v[(j<<k1)+i]; /* printf("Now = %d\n",now); */
			int p=1,q=1; dsu.init(n+k);
			int num_edge=0,num_node=n+popcount(i)+popcount(j);
			while(p<=s1[i] && q<=s2[j]){
				if(e1[i][p].w<e2[j][q].w){
					int fx=dsu.find(e1[i][p].u);
					int fy=dsu.find(e1[i][p].v);
					++p;
					if(fx==fy) continue;
//					printf("%d <--%d--> %d\n",e1[i][p-1].u,e1[i][p-1].w,e1[i][p-1].v);
					dsu.merge(fx,fy);
					++num_edge; now+=e1[i][p-1].w;
				}else{
					int fx=dsu.find(e2[j][q].u);
					int fy=dsu.find(e2[j][q].v);
					++q;
					if(fx==fy) continue;
//					printf("%d <--%d--> %d\n",e2[j][q-1].u,e2[j][q-1].w,e2[j][q-1].v);
					dsu.merge(fx,fy);
					++num_edge; now+=e2[j][q-1].w;
				}
				if(num_edge==num_node-1) break;
			}
			while(p<=s1[i] && num_edge<num_node-1){
				int fx=dsu.find(e1[i][p].u);
				int fy=dsu.find(e1[i][p].v);
				++p;
				if(fx==fy) continue;
//				printf("%d <--%d--> %d\n",e1[i][p-1].u,e1[i][p-1].w,e1[i][p-1].v);
				dsu.merge(fx,fy);
				++num_edge; now+=e1[i][p-1].w;
			}
			while(q<=s2[j] && num_edge<num_node-1){
				int fx=dsu.find(e2[j][q].u);
				int fy=dsu.find(e2[j][q].v);
				++q;
				if(fx==fy) continue;
//				printf("%d <--%d--> %d\n",e2[j][q-1].u,e2[j][q-1].w,e2[j][q-1].v);
				dsu.merge(fx,fy);
				++num_edge; now+=e2[j][q-1].w;
			}
//			printf("(%d, %d): %d\n",i,j,now);
			ans=min(ans,now);
		}
	}
	printf("%lld\n",ans);
	return 0;
}