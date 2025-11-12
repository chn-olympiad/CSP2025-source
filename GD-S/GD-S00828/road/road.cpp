#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fe(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define fi first
#define se second
#define mk make_pair
const int N=1e4+20,M=1e6+20;
int n,m,k,val[N],fa[N],len[11],sum;
pair<int,pair<int,int>>a[M],b[11][N],c[11][N*10];
ll ans=1e18;
int root(int u)
{
	if(fa[u]!=u) fa[u]=root(fa[u]);
	return fa[u];
}
inline int merge(pair<int,pair<int,int>>&d)
{
	int o=root(d.se.fi),p=root(d.se.se);
	if(o!=p)
	{
		--sum;
		fa[p]=o;
		return d.fi;
	}
	return 0;
}
void ovo(int u,ll s,int z)
{
	if(u==k+1)
	{
		sum=z+n-1;
		fo(i,1,n+k) fa[i]=i;
		int l=1,r=1;
		while(l<=len[u]&&r<=n-1&&sum)
			if(c[u][l].fi<a[r].fi) s+=merge(c[u][l++]);
			else s+=merge(a[r++]);
		while(l<=len[u]&&sum) s+=merge(c[u][l++]);
		while(r<=n-1&&sum) s+=merge(a[r++]);
		ans=min(ans,s);
		return ;
	}
	len[u+1]=len[u];
	fo(i,1,len[u]) c[u+1][i]=c[u][i];
	ovo(u+1,s,z);
	int l=1,r=1,cot=0;
	while(l<=len[u]&&r<=n)
		if(c[u][l].fi<b[u][r].fi) c[u+1][++cot]=c[u][l++];
		else c[u+1][++cot]=b[u][r++];
	while(l<=len[u]) c[u+1][++cot]=c[u][l++];
	while(r<=n) c[u+1][++cot]=b[u][r++];
	len[u+1]=cot;
	ovo(u+1,s+val[u],z+1);
}
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,m) a[i].se.fi=read(),a[i].se.se=read(),a[i].fi=read();
	fo(j,1,k)
	{
		val[j]=read();
		fo(i,1,n) b[j][i].se.fi=i,b[j][i].se.se=j+n,b[j][i].fi=read();
		sort(b[j]+1,b[j]+n+1);
	}
	sort(a+1,a+m+1);
	fo(i,1,n) fa[i]=i;
	int cot=0;
	fo(i,1,m)
	{
		int o=root(a[i].se.fi),p=root(a[i].se.se);
		if(o!=p) fa[p]=o,a[++cot]=a[i];
	}
	ovo(1,0,0),printf("%lld",ans);
	return 0;
}
