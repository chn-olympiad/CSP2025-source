#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> PII;

int read() {
	int n=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		n=(n<<1)+(n<<3)+ch-'0';
		ch=getchar();
	}
	return f==1?n:-n;
}

void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar((x%10)+'0');
}

//===========================================//

const int N=1e4+7,M=1e6+7,K=17;
const ll INF=1e18;

int n,m,k;

struct Edge{
	int u,v;
	ll w;
	friend bool operator <(const Edge &x,const Edge &y) {
		return x.w<y.w;
	}
}edge[M];

int w[K];
PII a[K][N];

//===========================================//

struct Dsu{
	
	int fa[N<<1];
	
	void init() {
		for(int i=1;i<=n+k;i++) 
			fa[i]=i;
	}
	
	int find(int x) {
		if(fa[x]!=x) fa[x]=find(fa[x]);
		return fa[x];
	}
	
	void merge(int a,int b) {
		a=find(a),b=find(b);
		fa[a]=b;
	}
	
	bool check(int a,int b) {
		return find(a)==find(b);
	}
	
}dsu;

//===========================================//

Edge e[N];

void init() {
	sort(edge+1,edge+1+m);
	dsu.init();
	int cnt=0;
	for(int i=1;i<=m;i++) {
		int u=edge[i].u,v=edge[i].v;
		if(dsu.check(u,v)) continue;
		else{
			e[++cnt]=edge[i];
			dsu.merge(u,v);
		}
	}
}

//===========================================//

ll ans;
int node[K],cnt;
int pe,p[K];

void solve(int sta) {
	ll res=0;
	cnt=0;
	for(int i=1;i<=k;i++) {
		if((sta>>i)&1) {
			node[++cnt]=i;
			res+=w[i];
		}
	}
	pe=1; for(int i=1;i<=cnt;i++) p[i]=1;
	dsu.init();
	for(int t=1;t<=n+cnt-1;t++) {
		while(pe<=n-1 && dsu.check(e[pe].u,e[pe].v)) pe++;
		for(int i=1;i<=cnt;i++) 
			while(p[i]<=n && dsu.check(node[i]+n,a[node[i]][p[i]].y)) p[i]++;
		ll w=INF;
		int u,v;
		if(pe<=n-1) w=e[pe].w,u=e[pe].u,v=e[pe].v;
		for(int i=1;i<=cnt;i++) 
			if(p[i]<=n) {
				if(a[node[i]][p[i]].x<w) {
					w=a[node[i]][p[i]].x;
					u=node[i]+n,v=a[node[i]][p[i]].y;
				}
			}
		res+=w;
		dsu.merge(u,v);
	}
	ans=min(ans,res);
}

//===========================================//

void input() {
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) 
		edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	for(int i=1;i<=k;i++) {
		w[i]=read();
		for(int j=1;j<=n;j++) 
			a[i][j].x=read(),a[i][j].y=j;
	}
}

void work() {
	init();
	for(int i=1;i<=k;i++) 
		sort(a[i]+1,a[i]+1+n);
	ans=INF;
	for(int sta=0;sta<(1<<k);sta++) 
		solve(sta);
	write(ans);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input();
	work();
	return 0;
}
