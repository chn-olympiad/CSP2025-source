#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000005;
ll c[N],cnt,ans=1e18;
int n,m,k,fa[N],siz[N],a[11][N];
bool flag[N];
struct node{
	int u,v,w;
	friend bool operator<(node x,node y){
		return x.w<y.w;
	}
}b[N],b2[N];
vector<pair<ll,ll> > G[N];
int getf(int x){
	if(x==fa[x])return x;
	return fa[x]=getf(fa[x]);
}
void dfs(ll dep,ll sum){
	if(dep==k+1){
		cnt=m;
		ll sum2=sum;
		for(int i=1;i<=m;i++)b[i]=b2[i];
		for(int i=1;i<=k;i++){
			if(!flag[i])continue;
			for(int j=1;j<=n;j++){
				b[++cnt]={i+n,j,a[i][j]};
			}
		}
		sort(b+1,b+1+cnt);
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			siz[i]=1;
		}
		for(int i=1;i<=cnt;i++){
			int x=getf(b[i].u),y=getf(b[i].v);
			if(x!=y){
				if(siz[x]<siz[y])swap(x,y);
				fa[y]=x;
				siz[x]+=siz[y];
				sum2+=b[i].w;
			}
		}
		ans=min(ans,sum2);
		return;
	}
	flag[dep]=1;
	dfs(dep+1,sum+c[dep]);
	flag[dep]=0;
	dfs(dep+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin >>b2[i].u>>b2[i].v>>b2[i].w;
	}
	bool f2=1;
	for(int i=1;i<=k;i++){
		cin >>c[i];
		for(int j=1;j<=n;j++)cin >>a[i][j];
		if(c[i])f2=0;
	}
	if(!f2){
		dfs(1,0);
		cout <<ans;
		return 0;
	}
	ans=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			b2[++m]={j,n+i,a[i][j]};
		} 
	}
	sort(b2+1,b2+1+m);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		int x=getf(b2[i].u),y=getf(b2[i].v);
		if(x!=y){
			if(siz[x]<siz[y])swap(x,y);
			fa[y]=x;
			siz[x]+=siz[y];
			ans+=b2[i].w;
			G[b2[i].u].push_back({b2[i].v,b2[i].w});
			G[b2[i].v].push_back({b2[i].u,b2[i].w});
		}
	}
	for(int i=n+1;i<=n+k;i++){
		if(G[i].size()==1)ans-=G[i][0].second;
	}
	cout <<ans;
}
