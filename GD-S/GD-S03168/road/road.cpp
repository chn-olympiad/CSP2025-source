#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define V vector
#define pii pair<ll,ll>
#define P priority_queue
typedef long long ll;
const int N=1e6+10;
ll T,n,m,k,c[N],a[11][100000],fa[N],cnt;
ll find(ll x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
struct node{
	ll u,v,w;
}e[N];
inline bool cmp(node& a,node& b){
	return a.w<b.w;
}
ll ks(){
	ll ans=0,dnt=0;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		ll u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			fa[u]=v;
			ans+=e[i].w;
			dnt++;
		}
		if(dnt==n-1)break;
	}
	return ans;
}
void init(){
	for(int i=1;i<=k;i++){
		ll p=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				p=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(j==p)continue;
			e[++cnt].u=p;
			e[cnt].v=j;
			e[cnt].w=a[i][j];
		}
	}
	return ;
}
void read(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){cin>>c[i];for(int j=1;j<=n;j++)cin>>a[i][j];}
}
V<pii>g[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read();
	cnt=m;
	if(k==0)return cout<<ks()<<endl,0;
	int op=0;
	for(int i=1;i<=k;i++){if(c[i]!=0){op=1;break;}}
	if(!op){
		init();
		cout<<ks()<<endl;
		return 0;
	}
	ll ans=0;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		ll u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			fa[u]=v;
			g[e[i].u].push_back({e[i].v,e[i].w});
			g[e[i].v].push_back({e[i].u,e[i].w});
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
