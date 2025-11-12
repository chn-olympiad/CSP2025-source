#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define psb push_back
const int N=1e5+10,M=1e6+10;
int n,m,k,c[15][N],f[N];
bool vis[N];
ll ans=1e15;
struct A{int u,v,w;}a[M],b[15][N];
inline int find(int x){return (f[x]==x?x:f[x]=find(f[x]));}
inline bool mrg(int x,int y){
	if((x=find(x))==(y=find(y))) return 0;
	return f[x]=y,1;
}
void cal(){
	int t=0;
	sort(a+1,a+m+1,[](A x,A y){return x.w<y.w;});
	for(int i=1;i<=n+k;++i) f[i]=i;
	for(int i=1;i<=m;++i)
		if(mrg(a[i].u,a[i].v)) a[++t]=a[i];
	m=t;
}
void dfs(int x){
	if(x>k){
		ll sum=0;
		for(int i=1;i<=k;++i)
			if(vis[i]) sum+=c[i][0];
		for(int i=1;i<=m;++i) sum+=a[i].w;
		ans=min(ans,sum);
		return;
	}
	int mm=m;
	for(int i=1;i<=m;++i) b[x][i]=a[i];
	vis[x]=0,dfs(x+1);
	for(int i=1;i<=n;++i) a[++m]={n+x,i,c[x][i]};
	cal();
	vis[x]=1,dfs(x+1);
	m=mm;
	for(int i=1;i<=m;++i) a[i]=b[x][i];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;++i)
		for(int j=0;j<=n;++j) cin>>c[i][j];
	cal(),dfs(1);
	cout<<ans;
	return 0;
}
