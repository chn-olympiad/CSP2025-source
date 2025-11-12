#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define pi pair<int,int>
#define eb emplace_back
#define vi vector<int>
#define fi first
#define se second
#define ll long long
using namespace std;
int read(){int s=0;char c=getchar();while(c<48||c>57)c=getchar();while(c>=48&&c<=57)s=(s<<3)+(s<<1)+c-48,c=getchar();return s;}
const int N=10107,M=1e6+7,K=13;
const ll inf=1e18;
int n,m,k,c[M],f[N],o,len[K],sz[N];
ll mn=inf;
struct edge{
	int x,y,z;
}e[M],p[K][N],a[K][N];
int fnd(int x){return x==f[x]?x:f[x]=fnd(f[x]);}
bool cmp(edge u,edge v){return u.z<v.z;}
void con(int x,int y)
{
	x=fnd(x);y=fnd(y);
	if(sz[x]>sz[y]) swap(x,y);
	f[x]=y,sz[y]+=sz[x];
}
void dfs(int x,ll s)
{
	if(x==k+1)
	{
		fo(i,1,len[k]) s+=p[k][i].z;
		mn=min(mn,s);
		return;
	}
	len[x]=len[x-1];
	fo(i,1,len[x]) p[x][i]=p[x-1][i];
	dfs(x+1,s);
	fo(i,1,n+k) f[i]=i,sz[i]=1;
	int l1=1,l2=1;
	len[x]=0;
	while(l1<=len[x-1]&&l2<=n)
	{
		edge cur;
		if(l2>n||(l1<=len[x-1]&&p[x-1][l1].z<a[x][l2].z)) cur=p[x-1][l1],l1++;
		else cur=a[x][l2],l2++;
		if(fnd(cur.x)!=fnd(cur.y)) p[x][++len[x]]=cur,con(cur.x,cur.y);
	}
	dfs(x+1,s+c[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	fo(i,1,m)
	{
		e[i].x=read();e[i].y=read();e[i].z=read();
	}
	sort(e+1,e+m+1,cmp);
	fo(i,1,n) f[i]=i,sz[i]=1;
	fo(i,1,m)
	{
		int x=e[i].x,y=e[i].y;
		if(fnd(x)!=fnd(y)) con(x,y),p[0][++len[0]]=e[i];
	}
	fo(i,1,k)
	{
		c[i]=read();
		fo(j,1,n)
		{
			a[i][j].z=read();
			a[i][j].x=n+i;a[i][j].y=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	dfs(1,0);
	printf("%lld",mn);
}
