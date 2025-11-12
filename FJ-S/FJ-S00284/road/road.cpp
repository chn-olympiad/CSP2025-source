// O(2^k kn)

#include <cstdio>
#include <algorithm>
using namespace std;

#define piii pair<int, pair<int, int>>
#define mpr make_pair
#define fi first
#define se second

void read(int &x){
	x=0;
	char ch=getchar();
	while (!isdigit(ch))	ch=getchar();
	while (isdigit(ch)){
		x*=10;
		x+=ch-48;
		ch=getchar();
	}
}

int n, m, k;
int c[11], a[11][10009];

int fa[10009];

void init(){
	for (int i=1; i<=n+k; i++)	fa[i]=i;
}

int get(int x){
	if (fa[x]==x)	return x;
	return fa[x]=get(fa[x]);
}

bool merge(int x, int y){
	x=get(x); y=get(y);
	fa[x]=y;
	return x!=y;
}

piii e1[1000009], e2[110009];

bool ok[100019];
long long ans=1e18;

void check(){
	long long res=0;
	init();
	for (int i=n+1; i<=n+k; i++)
		if (ok[i])
			res+=c[i-n];
	for (int i=1; i<=m; i++)
		if (ok[e2[i].se.fi] && merge(e2[i].se.fi, e2[i].se.se))
			res+=e2[i].fi;
	ans=min(ans, res);
}

void dfs(int x){
	if (x==n+k+1){
		check();
		return ;
	}
	ok[x]=1;
	dfs(x+1);
	ok[x]=0;
	dfs(x+1);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++){
		read(e1[i].se.fi);
		read(e1[i].se.se);
		read(e1[i].fi);
	}
	for (int i=1; i<=k; i++){
		read(c[i]);
		for (int j=1; j<=n; j++)
			read(a[i][j]);
	}
	
	sort(e1+1, e1+m+1);
	init();
	int tmp=0;
	for (int i=1; i<=m; i++)
		if (merge(e1[i].se.fi, e1[i].se.se))
			e2[++tmp]=e1[i];
	m=tmp;
	
	for (int i=1; i<=k; i++)
		for (int j=1; j<=n; j++)
			e2[++m]=mpr(a[i][j], mpr(n+i, j));
	sort(e2+1, e2+m+1);
	for (int i=1; i<=n; i++)	ok[i]=1;
	dfs(n+1);
	
	printf("%lld\n", ans);
	return 0;
}
