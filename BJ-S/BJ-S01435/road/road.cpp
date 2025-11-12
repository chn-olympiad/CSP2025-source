#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ullt=unsigned long long;
const ullt MAXN=1e4+10,MAXM=1e6+10,INF=0xfffffffffffffff;
struct Edge {
	int x,y,w;
};
int fa[MAXN],c[MAXN],vig[10][MAXN],n,m,k,realn;
ullt asw=INF;
vector<Edge> g,zlg;
void prework() {
	for (int i=1;i<=realn;i++) fa[i]=i;
}
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x),y=find(y);
	if (x!=y) fa[x]=y;
}
bool cmp(const Edge& a,const Edge& b) {
	return a.w<b.w;
}
ullt mst() {
	sort(zlg.begin(),zlg.end(),cmp);
	prework();
	ullt res=0;
	int cnt=1;
	for (auto e:zlg) {
		if (find(e.x)==find(e.y)) continue;
		merge(e.x,e.y);
		res+=e.w;
		cnt++;
		if (cnt>=realn) break;
		if (res>asw) return INF;
	}
	return res;
}
int main() {
	// i want to play delta force!!
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	realn=n+k;
	for (int i=0;i<m;i++) {
		int x,y,w;
		cin>>x>>y>>w;
		g.push_back({x,y,w});
	}
	int sumc=0;
	for (int i=0;i<k;i++) {
		cin>>c[i];
		if (c[i]) sumc=1;
		for (int j=1;j<=n;j++) {
			cin>>vig[i][j];
		}
	}
	int bit2en=0;
	if (!sumc) {
		//puts("enable fast compete");
		for (int i=0;i<k;i++) {
			bit2en|=(1<<i);
		}
	}
	for (;bit2en<(1<<k);bit2en++) {
		zlg=g;
		ullt attend=0;
		for (int i=0;i<k;i++) {
			if ((bit2en>>i)&1) {
				attend+=c[i];
				for (int j=1;j<=n;j++) {
					zlg.push_back({n+1+i,j,vig[i][j]});
				}
			}
		}
		//puts("OK");
		ullt rep=mst();
		asw=min(rep+attend,asw);
	}
	cout<<asw;
	return 0;
}
