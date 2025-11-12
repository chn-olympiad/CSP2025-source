#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define int long long
#define MM 1000010
#define N 10010
#define M 20
using namespace std;
int n,m,k,p[M],a[N][M],t[N][M],fa[N]; // t[N][M]
struct Node{
	int id,minn;
	bool operator<(const Node &__) const {
		if (minn==__.minn) return id<__.id;
		return minn<__.minn;
	}
};
set<Node> st[M];
bool vis[N];
struct Edge{
	int u,v,w;
}e[MM];
bool cmp(Edge _1,Edge _2) {
	return _1.w<_2.w;
}
int find(int x) {return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
void merge(int fx,int fy) { 
	fa[fy]=fx; // 把 fy 并到 fx
	for (int i=1;i<=k;i++) {
		// 需要在 st[i] 中找到 fx 与 fy，将他们合并
		int dx=t[fx][i],dy=t[fy][i];
//		cout << " " << fx << " " << fy << " " << dx << " " << dy << endl;
//		for (auto it:st[i]) cout << " " << it.id << " " << it.minn << endl;
		st[i].erase(st[i].find(Node{fx,dx}));
		st[i].erase(st[i].find(Node{fy,dy}));
//		cout << "E " << fx << " " << dx << endl;
//		cout << "E " << fy << " " << dy << endl;
//		cout << "I " << fx << " " << dx+dy << endl;
		st[i].insert(Node{fx,min(dx,dy)});
//		for (auto it:st[i]) cout << " " << it.id << " " << it.minn << endl;
		t[fx][i]=min(dx,dy);
//		t[fy][i]=1e18;
	}
}
signed main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e+1,e+1+m,cmp);
//	for (int i=1;i<=m;i++) cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
	for (int i=1;i<=k;i++) {
		cin >> p[i];
		for (int j=1;j<=n;j++) {
			cin >> a[j][i];
			t[j][i]=a[j][i];
			st[i].insert(Node{j,a[j][i]});
		}
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	int ans=0,pp=0;
	for (int i=1;i<=m;) {
		if (find(e[i].u)==find(e[i].v)) {i++;continue;}
//		cout << i << " " << pp << endl;
		if (pp==n-1) break;
		int minmun=1e18,x,y,cp; // 这里是表示求出来最小和
		if (st[1].size()>1) {
			for (int j=1;j<=k;j++) {
				auto it2=st[j].begin();
				auto it1=it2;
				it2++;
				// 求出来当前最小
				int ccc=p[j];
				if (vis[j]) ccc=0;
				if ((*it1).minn+(*it2).minn+ccc<minmun) {
					minmun=(*it1).minn+(*it2).minn+ccc;
					x=(*it1).id;
					y=(*it2).id;
					cp=j;
//					cout << x << " " << y << " " << (*it1).minn << " " << (*it2).minn << " " << j << endl;
				}
			}
		}
//		cout << "  " << x << " " << y << " " << minmun << endl;
		// 比较一下那个好
		if (e[i].w<=minmun) {
			int fx=find(e[i].u),fy=find(e[i].v);
			if (fx!=fy) {
//				cout << fx << " " << fy << endl;
				merge(fx,fy); // 这里是合并
//				cout << fx << " " << fy << endl;
				ans+=e[i].w;
//				cout << "1 " << fx << " " << fy << " " << e[i].w << endl;
				pp++;
			}
			i++;
		} else {
//			cout << x << " " << y << endl;
			merge(x,y);
			pp++;
//			cout << x << " " << y << endl;
			ans+=minmun;
			vis[cp]=1;
//			cout << "2 " << x << " " << y << " " << minmun << endl;
		}
	}
	cout << ans;
	return 0;
}
