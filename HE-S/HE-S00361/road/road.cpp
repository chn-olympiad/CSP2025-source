#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
struct edge{
	int u,v,w,idx;
}e[N];
int n,m,k,ans,cnt;
int fa[N],c[N],s[N];
int vis[N],f[N];
map<int,map<int,int> > a;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve(){
	int t=0;
	for(int i=1;i<=cnt;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v) continue;
		t++;
		if(e[i].idx>m&&!vis[e[i].idx]){
			ans+=c[e[i].idx];
			t--;
		}
		if(e[i].idx>m){
			a[e[i].idx][v]=a[v][e[i].idx]=1;
			ans+=e[i].w-c[e[i].idx],vis[e[i].idx]++;
		}else ans+=e[i].w;
		fa[v]=u;
		f[i]=1;
		if(t==n-1) return ;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].idx=i;
	}
	cnt=m;
	for(int i=1+m;i<=k+m;i++){
		cin>>c[i];
		s[i]=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			int x; cin>>x;
			e[++cnt].u=i,e[cnt].v=j,e[cnt].w=x+c[i];
			e[cnt].idx=i;
			s[i]=min(s[i],x);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	solve();
	for(int i=1+m;i<=k+m;i++){
		if(vis[i]==1){
			ans-=(c[i]+s[i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
