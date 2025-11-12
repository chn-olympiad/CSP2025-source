#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+13,M=2e6+13;
struct ed{int x;ll d;};
struct eds{int x,y;ll d;}g[M];
bool operator<(eds u,eds v){return u.d<v.d;}
vector<ed>e[N];
int n,m,k,fa[N],dep[N];
ll a[13][N];
ll s,ans=1e18;
int fd(int x){
	if(fa[x]==x)return x;
	int u=fd(fa[x]);fa[x]=u,dep[x]=dep[u]+1;
	return u;
}
bool un(int x,int y){
	int u=fd(x),v=fd(y);
	if(u==v)return 1;
	if(dep[u]>dep[v])fa[v]=u,dep[v]=dep[u]+1;
	else fa[u]=v,dep[u]=dep[v]+1;
	return 0;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i,dep[i]=0;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		g[i]={u,v,w};
		e[u].push_back({u,w});
		e[v].push_back({u,w});
	}
	bool f0=0;
	for(int j=1;j<=k;j++){
		cin>>a[j][0];if(a[j][0])f0=1;
		for(int i=1;i<=n;i++)cin>>a[j][i];
	}
	if(!f0){
		for(int j=1;j<=k;j++){
			int gi=0,gm=2e9;
			for(int i=1;i<=n;i++)if(!a[j][i])gi=i;
			for(int i=1;i<=n;i++){
				if(i!=gi)g[++m]={gi,i,a[j][i]};
			}
		}
		sort(g+1,g+m+1);
		for(int i=1,h=1;i<=m&&h<=n-1;i++){
			if(!un(g[i].x,g[i].y))++h,s+=g[i].d;
		}
		cout<<s;
		return 0;
	}
	int qm=m,bk=(1<<k);
	for(int b=0;b<bk;b++){
		m=qm;s=0;int tb=0;
		for(int j=1;j<=k;j++)if((b>>(j-1))&1){
			++tb;
			s+=a[j][0];
			for(int i=1;i<=n;i++){
				g[++m]={n+j,i,a[j][i]};
			}
		}
		for(int i=1;i<=n+k;i++)fa[i]=i,dep[i]=0;
		sort(g+1,g+m+1);
		for(int i=1,h=1;i<=m&&h<=n+2*tb-1;i++){
			if(!un(g[i].x,g[i].y))++h,s+=g[i].d;
		}
		//cout<<s<<'\n';
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}
