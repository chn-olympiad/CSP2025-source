#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,x,y,w,cnt,a[15],p[15],g[3005][3005],fa[10005],ans;
struct N{ll x,y,w;}s[9000005];
bool cmp(N a,N b){return a.w<b.w;}
ll fd(ll x){
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		if(x>y) swap(x,y);
		g[x][y]=min(g[x][y],w);
	}
	memset(s,0x3f,sizeof(s));
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			cin>>p[j];
			for(int k=1;k<j;k++) g[k][j]=min(g[k][j],p[j]+p[k]);
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		for(int j=1;j<=n;j++){
			s[++cnt].x=i;
			s[cnt].y=j;
			s[cnt].w=g[i][j];
		}
	}
	sort(s+1,s+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		ll x=s[i].x,y=s[i].y,w=s[i].w,fx=fd(x),fy=fd(y);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
