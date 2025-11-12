#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define ari(x) array<int,(x)>
#define lowbit(x) ((x) -(x))

const int N = 11005,M = 6e6+5,K = 85;
struct node{int x,y,w;}a[M];
struct town{int c1,c[N];}b[K];
vector<int> v;
int vis[K];
int f[N],n,m,k,ans,cans;
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
bool cmp(const node &x,const node &y){return x.w < y.w;}
int solve();
void dfs(int xx){
	if(xx > k){
		ans = min(ans,solve());
		return;
	}
	vis[xx] = false;
	dfs(xx+1);
	if(b[xx].c1 > cans) return;
	vis[xx] = true;
	dfs(xx+1);
	vis[xx] = false;
}
int solve(){
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1;i <= k;i++) f[i+n] = i+n;
	int nm = m;
	int cost = 0,xkcnt = 0;
	for(int i = 1;i <= nm;i++){
		if(!vis[i]) continue;
		xkcnt++;
		cost+=b[i].c1;
		for(int j = 1;j <= n;j++)
			a[++nm] = {n+i,j,b[i].c[j]};
	}
	sort(a+1,a+nm+1,cmp);
	int cnt = 0;
	for(int i = 1;i <= nm;i++){
		int fx = find(a[i].x);
		int fy = find(a[i].y);
		if(fx != fy){
			f[fx] = fy;
			cnt++;
			cost+=a[i].w;
			if(cnt == n-1+xkcnt) break;
		}
	}
	return cost;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++) cin>>a[i].x>>a[i].y>>a[i].w;
	for(int i = 1;i <= k;i++){
		cin>>b[i].c1;
		for(int j = 1;j <= n;j++) cin>>b[i].c[j];
	}
	sort(a+1,a+m+1,cmp);
	ans = cans = solve();
	dfs(1);
	cout<<ans;
	return 0;
}
