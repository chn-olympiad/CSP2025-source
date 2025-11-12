#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define lowbit(x) (x)&(-x)
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
struct edge{
	int u,v,w;
}e[M],t[N];
ll ans;
int n,m,k,T,a[11][N],c[11],f[N],cnt,mn[11];
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
inline int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(register int i=1;i<=m;++i) e[i]={read(),read(),read()};
	for(register int i=1;i<=k;++i){
		c[i]=read();
		for(register int j=1;j<=n;++j){
			a[i][j]=read();
			if(!mn[i]||a[i][j]<a[i][mn[i]]) mn[i]=j;
		}
	}
	sort(e+1,e+m+1,[](edge a,edge b){return a.w<b.w;});
	for(register int i=1;i<=n;++i) f[i]=i;
	ll tot=0;int cnt=0;
	for(register int i=1;i<=m;++i){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v) continue;
		f[u]=v;tot+=e[i].w;
		t[++cnt]=e[i];
		if(cnt==n-1) break;
	}
	ans=tot;
	for(register int i=1;i<(1<<k);++i){
		cnt=0;
		ll res=0;
		for(register int j=1;j<n;++j) e[++cnt]=t[j];
		for(register int j=1;j<=k;++j){
			if(!(i>>(j-1)&1)) continue;
			res+=c[j]+a[j][mn[j]];
			for(register int l=1;l<=n;++l) if(l!=mn[j]) e[++cnt]={l,mn[j],a[j][l]};
		}
		sort(e+1,e+cnt+1,[](edge a,edge b){return a.w<b.w;});
		int ecnt=0;
		for(register int j=1;j<=n;++j) f[j]=j;
		for(register int j=1;j<=cnt;++j){
			int u=find(e[j].u),v=find(e[j].v);
			if(u==v) continue;
			++ecnt;
			res+=e[j].w;f[u]=v;
			if(ecnt==n-1) break;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}

