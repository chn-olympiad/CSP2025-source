#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define powi2(x) ((x)*(x))
#define pow2i(x) (1<<(x))
//#define int long long
using namespace std;
const int N = 1e4+5,M = 1e6+5;
struct edge {int u,v,w;} e[M];
int n,m,k,fa[N],si[N],cnt,ans;
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int x,int y)
{
	x = find(x),y = find(y);
	if (si[x] < si[y]) swap(x,y);
	si[x] += si[y],fa[y] = x;
}
bool check(int x,int y) {return find(x) == find(y);}
start_code
openfile(road);
cin>>n>>m>>k;
for (int i = 1;i <= m;i ++) cin>>e[i].u>>e[i].v>>e[i].w;
for (int i = 1;i <= n;i ++) fa[i] = i,si[i] = 1;
sort(e+1,e+m+1,[](const edge&x,const edge&y){return x.w<y.w;});
for (int i = 1;i <= m;i ++)
{
	if (!check(e[i].u,e[i].v)) unite(e[i].u,e[i].v),ans += e[i].w,cnt ++;
	if (cnt == n-1) break ;
}
cout<<ans;
stop_code
/*
#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define powi2(x) ((x)*(x))
#define pow2i(x) (1<<(x))
//#define int long long
using namespace std;
const int N = 1e4+5,M = 1e6+5;
struct edge {int u,v,w;} e[M];
int n,m,k,fa[N],si[N],cnt,ans,c[15],a[15][N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int x,int y)
{
	x = find(x),y = find(y);
	if (si[x] < si[y]) swap(x,y);
	si[x] += si[y],fa[y] = x;
}
bool check(int x,int y) {return find(x) == find(y);}
vector<pair<int,int> > g[N];
start_code
cin>>n>>m>>k;
for (int i = 1;i <= m;i ++) cin>>e[i].u>>e[i].v>>e[i].w;
for (int i = 1;i <= n;i ++) fa[i] = i,si[i] = 1;
sort(e+1,e+m+1,[](const edge&x,const edge&y){return x.w<y.w;});
for (int i = 1;i <= m;i ++)
{
	if (!check(e[i].u,e[i].v))
		unite(e[i].u,e[i].v),ans += e[i].w,cnt ++,
		g[e[i].u].push_back({e[i].v,e[i].w}),g[e[i].v].push_back({e[i].u,e[i].w});
	if (cnt == n-1) break ;
}
if (k == 0) cout<<ans,exit(0);
for (int i = 1,ans2;i <= k;i ++)
{
	cin>>c[i];
	for (int j = 1;j <= n;j ++) cin>>a[i][j];
	for (int j = 1;j <= n;j ++)
	{
		ans2 = ans;
		for (auto v:g[j]) ans2 -= v.second;
		for (auto v:g[j]) ans2 += min(v.second,a[i][j]+c[i]+a[i][v.first]);
		
	}
}
stop_code
*/
