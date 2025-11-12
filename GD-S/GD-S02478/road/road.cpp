#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n, m, k;

int elen=0;
int f[10010];
int a[15][10010], c[15];
bool b[15];
ll ans=1e18;

struct node{
	int x, y;
	ll w;
}g[1000010];

struct edge{
	int x, y, w;
}e[4000010];

int findfa(int x){
	return f[x]=f[x]==x?x:findfa(f[x]); 
}

void ins(int x, int y, int w){
	e[++elen]=edge{x, y, w};
}

bool cmp(edge x, edge y){
	return x.w<y.w;
}

void solve(){
	for(int i=1; i<=n+k; i++) f[i]=i;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			ins(i+n, j, a[i][j]);
		}
	}
	sort(e+1, e+elen+1, cmp);
	int cnt=n+k-1;
	ans=0;
	for(int i=1; i<=elen; i++){
		if(cnt==0) break;
		int x=e[i].x, y=e[i].y, w=e[i].w;
		int xx=findfa(x), yy=findfa(y);
		if(xx!=yy){
			f[xx]=yy;
			cnt--;
			ans+=w;
		}
	}
}

void dfs(int d){
	if(d==k+1){
		for(int i=1; i<=n+k; i++) f[i]=i;
		elen=0;
		for(int i=1; i<=m; i++){
			ins(g[i].x, g[i].y, g[i].w);
		}
		int cnt=n-1;
		ll sum=0;
		for(int i=1; i<=k; i++){
			if(b[i]){
				cnt++;
				sum+=c[i];
				for(int j=1; j<=n; j++){
					ins(i+n, j, a[i][j]);
				}
			}
		}
		sort(e+1, e+elen+1, cmp);
		for(int i=1; i<=elen; i++){
			if(cnt==0) break;
			int x=e[i].x, y=e[i].y, w=e[i].w;
			int xx=findfa(x), yy=findfa(y);
			if(xx!=yy){
				f[xx]=yy;
				cnt--;
				sum+=w;
			}
		}
		ans=min(ans, sum);
		return ;
	}
	b[d]=true;
	dfs(d+1);
	b[d]=false;
	dfs(d+1);
}

void solve2(){
	dfs(1);
}

int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		g[i]={x, y, w};
		ins(x, y, w);
	}
	bool flag=true;
	for(int i=1; i<=k; i++){
		cin >> c[i];
		if(c[i]!=0) flag=false;
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	if(flag) solve();
	else solve2();
	cout << ans << '\n';
	
	return 0;
}
