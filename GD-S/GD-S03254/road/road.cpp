#include<algorithm>
#include<stdio.h>
#include<queue>
#define ll long long
#define N 10005
#define M 2000005

using namespace std;

ll rd() {
	char c=getchar(); ll x=0, y=1;
	while(!(c >= '0' && c <= '9' || c == '-')) c=getchar();
	if(c == '-') y=-1, c=getchar();
	while(c >= '0' && c <= '9') x=x*10+c-'0', c=getchar();
	return x*y;
}
int n, m, k;
int head[N], to[M], nex[M], len[M], m1=1;
void add(int u, int v, int w) {to[++m1]=v, nex[m1]=head[u], head[u]=m1, len[m1]=w;}

int con[15][N], cs[15];

struct edge {
	int u, v, w;
} E[M], E1[15][N]; int ne;
bool cmpe(edge x, edge y) {return x.w < y.w;}
int fa[N];
int find(int x) {return fa[x] == x ? x : fa[x]=find(fa[x]);}
struct node {
	int x, y, z;
};
struct cmpn {
	bool operator () (node x, node y) {return x.x > y.x;}
};
ll solve(int s) {
	ne=0;
	for(int i=1; i<=n+k; i++) fa[i]=i;
	ll sum=0; 
	int cnt=n;
	priority_queue<node, vector<node>, cmpn> que;
	que.push({E[1].w, -1, 1});
	for(int i=0; i<k; i++) {
		if(s&(1<<i)) {
			sum+=cs[i];
			cnt++;
			que.push({E1[i][1].w, i, 1});
		}
	}
	while(!que.empty()) {
		node now=que.top(); que.pop();
		edge cur;
		if(now.y == -1) {
			cur=E[now.z];
			if(now.z+1 <= m) que.push({E[now.z+1].w, -1, now.z+1});
		} 
		else {
			cur=E1[now.y][now.z];
			if(now.z+1 <= n) que.push({E1[now.y][now.z+1].w, now.y, now.z+1});
		}
//		printf("%d %d %d\n", cur.u, cur.v, cur.w);
		int u=find(cur.u), v=find(cur.v);
		if(u == v) continue;
		sum+=cur.w;
		fa[u]=v, cnt--;
		if(cnt == 1) break;
	}
//	printf("\n");
	return sum;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n=rd(), m=rd(), k=rd();
	for(int i=1; i<=m; i++) {
		int u=rd(), v=rd(), w=rd();
		add(u, v, w), add(v, u, w);
		E[i]={u, v, w};
	}
	sort(E+1, E+m+1, cmpe);
	for(int i=0; i<k; i++) {
		cs[i]=rd(); for(int j=1; j<=n; j++) con[i][j]=rd(), E1[i][j]={n+i+1, j, con[i][j]};
		sort(E1[i]+1, E1[i]+n+1, cmpe);
//		for(int j=1; j<=n; j++) printf("%d:%d:%d ", E1[i][j].u, E1[i][j].v, E1[i][j].w); printf("\n");
	}
//	pre();
	ll ans=1e18;
	for(int s=0; s<(1<<k); s++) {
		ans=min(ans, solve(s));
	} 
	printf("%lld", ans);
	return 0;
}

