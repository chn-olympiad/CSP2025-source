#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
const int M=1e4+10;

int f[N];
int sum[M],vis[M],viss[N];

struct edge {
	int from,to,v,b,c;
	
	bool operator < (const edge &b) const { 
	    return this->v>b.v; 
	}
};

int find(int x) {
	if (x==f[x]) return x;
	return f[x]=find(f[x]);
}

priority_queue <edge, vector<edge>, less<edge> > q;

void solve1(int n) {
	int ans=0;
	while (!q.empty()) {
		edge tmp=q.top();
		q.pop();
		if (!viss[tmp.from]||!viss[tmp.to]) {
			viss[tmp.from]=viss[tmp.to]=1;
			ans+=tmp.v;
		} 
		int f=1;
		for (int i=1;i<=n;i++) {
			if (!viss[i]) f=0;
		}
		if (f) break;
	}
	printf("%d", ans);
	return ;
}

int main() {
	freopen("road2.in", "r", stdin);
	freopen("road2.out", "w", stdout);
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1;i<=n;i++) {
		f[i]=i;
	}
	for (int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d", &u, &v, &w);
		q.push({u,v,w,0,0});
	}
	for (int i=1;i<=k;i++) {
		int c;
		scanf("%d", &c);
		for (int j=1;j<=n;j++) {
			scanf("%d", &sum[j]);
		}
		for (int j=1;j<=n;j++) {
			for (int x=j+1;x<=n;x++) {
				q.push({j,x,sum[j]+sum[x],i,c});
			}
		}
	}
	if (k==0) {
		solve1(n);
		return 0;
	}
	int ans=0;
	while (!q.empty()) {
		edge tmp=q.top();
		q.pop();
		if (!viss[tmp.from]||!viss[tmp.to]) {
			viss[tmp.from]=viss[tmp.to]=1;
			if (!vis[tmp.b]) tmp.v+=tmp.c;
			if (tmp.b) vis[tmp.b]=1;
			ans+=tmp.v;
		} 
		int f=1;
		for (int i=1;i<=n;i++) {
			if (!viss[i]) f=0;
		}
		if (f) break;
	}
	printf("%d", ans);
	return 0;
}
