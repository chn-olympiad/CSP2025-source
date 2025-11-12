#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxm=1e6+10;
const int maxn=1.5e5+10;
struct T{
	int u,v,w;
	bool operator <(const T &r)const{
		return w<r.w;
	}
}e[maxm],g[maxn],a[15][maxn],tmp[maxn],fw[maxn];
int n,m,k,c[maxn];
int sz[maxn],fa[maxn];
ll mn=1e18;
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 0;
	if(sz[x]>sz[y]) swap(x,y);
	fa[x]=y,sz[y]+=sz[x];
	return 1;
}
inline void resort(int x){
	int j=1,tot=0;
	for(int i=1;i<=n;i++){
		while(j<=m&&g[j].w<a[x][i].w) tmp[++tot]=g[j++];
		tmp[++tot]=a[x][i];
	}
	while(j<=m) tmp[++tot]=g[j++];
	swap(g,tmp);
	m=tot;
}
inline ll sol(){
	for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		//cerr<<u<<' '<<v<<' '<<w<<endl;
		if(merge(u,v)) ans+=w;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m);
	ll ans=0;
	int tot=0;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(merge(u,v)) ans+=w,g[++tot]=e[i];
	}
	memcpy(fw,g,sizeof(fw));
	mn=ans;
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			a[i][j].u=i+n+1;
			a[i][j].v=j;
			cin>>a[i][j].w;
		}
		sort(a[i]+1,a[i]+1+n);
	}
	for(int i=1;i<1<<k;i++){
		memcpy(g,fw,sizeof(g));
		m=tot;
		ans=0;
		for(int j=0;j<k;j++)
			if(i>>j&1){
				ans+=c[j];
				resort(j);
			}
		ans+=sol();
		mn=min(mn,ans);
	}
	cout<<mn<<endl;
	return 0;
}
