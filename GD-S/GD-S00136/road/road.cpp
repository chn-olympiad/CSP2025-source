#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e4+100,M=1e6+100;
const ll inf=1e18;
int fa[N],siz[N],n,k;
void init(){
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
}
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return false;
	if(siz[u]>siz[v])swap(u,v);
	fa[u]=v,siz[v]+=siz[u];
	return true;
}
struct edge{int u,v,w;}e[M],g[M],c[12][N],a[12][N];
int work(int m){
	init();
	int idx=0;
	for(int i=1;i<=m;i++){
		bool flag=merge(e[i].u,e[i].v);
		if(flag)g[++idx]=e[i];
	}
	return idx;
}
bool operator <(edge a,edge b){return a.w<b.w;}
int m,val[N];
ll ans=inf;
void check(int cnt,ll sum){
	for(int i=1;i<=cnt;i++)sum+=c[k][i].w;
	ans=min(ans,sum);
}
void dfs(int i,int cnt,ll sum){
	if(i>k)return check(cnt,sum);
	for(int j=1;j<=cnt;j++)c[i][j]=c[i-1][j];
	dfs(i+1,cnt,sum);
	for(int j=1;j<=cnt;j++)e[j]=c[i-1][j];
	for(int j=1;j<=n;j++)e[j+cnt]=a[i][j];
	inplace_merge(e+1,e+cnt+1,e+cnt+n+1);
	cnt=work(cnt+n),sum+=val[i];
	for(int j=1;j<=cnt;j++)c[i][j]=g[j];
	dfs(i+1,cnt,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			a[i][j]={i+n,j,x};
		}
		sort(a[i]+1,a[i]+n+1);
	}
	sort(e+1,e+m+1);
	work(m);
	for(int i=1;i<n;i++)c[0][i]=g[i];
	dfs(1,n-1,0);
	cout<<ans<<endl;
}

