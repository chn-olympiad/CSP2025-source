#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+10,maxm=1e6+10,inf=0x3f3f3f3f3f3f3f3f;
struct edge{int u,v,w;}a[11][maxn],b[maxm],e[maxm<<1],t[maxm<<1];
bool operator <(const edge& x,const edge& y){return x.w<y.w;}
int c[maxn],fa[maxn],sz[maxn];
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		b[i]={u,v,w};
	}
	sort(b+1,b+m+1);
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			int w;cin>>w;
			a[j][i]={i,j+n,w};
		}
		sort(a[j]+1,a[j]+n+1);
	}
	int ans=inf;
	{
		int S=0;
		int tm=m,tn=n,ts=0;
		for(int i=1;i<=tm;i++)e[i]=b[i];
		for(int j=1;j<=k;j++){
			if(!(S>>j&1))continue;
			merge(e+1,e+tm+1,a[j]+1,a[j]+n+1,t+1);
			tm+=n;tn++;ts+=c[j];
			for(int i=1;i<=tm;i++)e[i]=t[i];
		}
		for(int i=1;i<=tn;i++)fa[i]=i,sz[i]=1;
		int sum=0,cnt=0;
		for(int i=1;i<=tm;i++){
			auto [u,v,w]=e[i];
			u=find(u);v=find(v);
			if(u==v)continue;
			if(sz[u]<sz[v])swap(u,v);
			fa[u]=v;sz[v]+=sz[u];sum+=w;
			if(++cnt==tn-1)break;
		}
		if(cnt==tn-1)ans=min(ans,sum+ts);
	}{
		int S=(2<<k)-2;
		int tm=m,tn=n,ts=0;
		for(int i=1;i<=tm;i++)e[i]=b[i];
		for(int j=1;j<=k;j++){
			if(!(S>>j&1))continue;
			merge(e+1,e+tm+1,a[j]+1,a[j]+n+1,t+1);
			tm+=n;tn++;ts+=c[j];
			for(int i=1;i<=tm;i++)e[i]=t[i];
		}
		for(int i=1;i<=tn;i++)fa[i]=i,sz[i]=1;
		int sum=0,cnt=0;
		for(int i=1;i<=tm;i++){
			auto [u,v,w]=e[i];
			u=find(u);v=find(v);
			if(u==v)continue;
			if(sz[u]<sz[v])swap(u,v);
			fa[u]=v;sz[v]+=sz[u];sum+=w;
			if(++cnt==tn-1)break;
		}
		if(cnt==tn-1)ans=min(ans,sum+ts);
	}
	m=min(m,(int)(4e7)/(1<<k));
	for(int S=2;S<(2<<k)-2;S+=2){
		int tm=m,tn=n,ts=0;
		for(int i=1;i<=tm;i++)e[i]=b[i];
		for(int j=1;j<=k;j++){
			if(!(S>>j&1))continue;
			merge(e+1,e+tm+1,a[j]+1,a[j]+n+1,t+1);
			tm+=n;tn++;ts+=c[j];
			for(int i=1;i<=tm;i++)e[i]=t[i];
		}
		for(int i=1;i<=tn;i++)fa[i]=i,sz[i]=1;
		int sum=0,cnt=0;
		for(int i=1;i<=tm;i++){
			auto [u,v,w]=e[i];
			u=find(u);v=find(v);
			if(u==v)continue;
			if(sz[u]<sz[v])swap(u,v);
			fa[u]=v;sz[v]+=sz[u];sum+=w;
			if(++cnt==tn-1)break;
		}
		if(cnt==tn-1)ans=min(ans,sum+ts);
	}
	cout<<ans;
	return 0;
}
//$O(2^k m)$, best wishes.
