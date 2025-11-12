#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,k,x,y,z,f[10011],w[11],ans=LLONG_MAX;
struct edge
{
	int u,v,w;
	edge(int u=0,int v=0,int w=0) :u(u),v(v),w(w) {}
	bool operator<(edge a) const { return w<a.w; }
}e[1100001];
inline int read()
{
	int s=0,f=1;
	char c=getchar();
	while(!isdigit(c)) f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c)) s=(s<<3)+(s<<1)+(c&15),c=getchar();
	return s*f;
}
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
bool merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v) return false;
	f[v]=u;
	return true;
}
int sum(int x) 
{
	int ret=0;
	while(x) ret+=(x&1),x>>=1;
	return ret;
}
int make_tree(int x)
{
	int ret=0,cnt=0,s=sum(x);
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=k;i++) if((x>>(i-1))&1) ret+=w[i];
	for(int i=1;i<=m+k*n&&cnt<n+s;i++)
	{
		if((e[i].u<=n||(x>>(e[i].u-n-1)&1))&&merge(e[i].u,e[i].v)) ret+=e[i].w,cnt++;
		if(m+k*n-i<n+s-1-cnt) return LLONG_MAX;
	}
	return ret;
}
signed main()
{
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) x=read(),y=read(),z=read(),e[i]=edge(x,y,z);
	for(int i=1;i<=k;i++)
	{
		w[i]=read();
		for(int j=1;j<=n;j++) x=read(),e[m+(i-1)*n+j]=edge(i+n,j,x);
	}
	sort(e+1,e+m+k*n+1);
	for(int i=0;i<(1<<k);i++) ans=min(ans,make_tree(i));
	cout<<ans;
}
