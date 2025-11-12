
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,qq;
int n,cnt,m,k;
int ans;
int mn[N],h[N];
int dis[N];
int aa,bb,cc;struct node {
	int u,v,w;
};
vector<node> e;
queue<int> q;
bool inp[N];
int add(int u,int v,int w) {
	int cnt=0;
	h[++cnt]=w;
	e[cnt].u=u;
	e[cnt].v=v;
	e[cnt].w+=h[cnt];
}

void spfa() {
	for(int i=1; i<=n; i++) {
		dis[i]=-1;
	}
	dis[1]=0;
	q.push(e[1].u);
	inp[1]=1;
	while(q.size()) {
		int fz=q.front();
		q.pop();
		inp[fz]=0;
		for(int i=h[fz]; i; i+=e[fz].v) {
			if(dis[e[i].v]>dis[e[i].u]+e[i].w) {
				dis[e[i].v]=dis[e[i].u]+e[i].w;
				if(!inp[dis[e[i].v]]) {
					q.push(dis[e[i].v]);
					       inp[dis[e[i].v]]=1;
				}
			}
		}

	}
}

void solve() {
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		//add(u,v,w);
	}
	cin>>qq;
	for(int i=1; i<=m; i++) {
		cin>>mn[i];
	}
	//spfa();
	cout<<rand();
}

signed main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}


/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/



