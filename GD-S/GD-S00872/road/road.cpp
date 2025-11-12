#include<bits/stdc++.h>
#define file(NAME)\
	freopen(NAME".in","r",stdin);\
	freopen(NAME".out","w",stdout);
#define ll long long
#define rep(i,x,y) for(int i=x,y_=y;i<=y_;i++)
#define per(i,x,y) for(int i=y,x_=x;i>=x_;i--)
using namespace std;
char ch;
void rd(int &x)
{
	for(ch=0;ch<'0'||ch>'9';ch=getchar());
	for(x=0;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
}
const int N=1e4+20,M=1e6+5,K=15,P=998244353;
int n,m,k,c[K],h;
int fa[N];
int fd(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
int t,bz[K],l,r;
ll z=1e18;
struct Edge {int u,v,w;}b[M],d[N],f[M];
bool cmp(Edge x,Edge y) {return x.w<y.w;}
void dg(int x,ll y)
{
	if(x>k)
	{
		rep(i,1,n+k) fa[i]=i;
		l=1,r=1;
		while(bz[f[l].v-n]==0&&l<=t) l++;
		while(l<=t||r<=h)
		{
			if(l>t||(r<=h&&d[r].w<f[l].w))
			{
				if(fd(d[r].u)!=fd(d[r].v))
					fa[fd(d[r].u)]=fd(d[r].v),y+=d[r].w;
				r++;
			}
			else
			{
				if(fd(f[l].u)!=fd(f[l].v))
					fa[fd(f[l].u)]=fd(f[l].v),y+=f[l].w;
				l++;
				while(bz[f[l].v-n]==0&&l<=t) l++;
			}
		}
		z=min(z,y);
		return;
	}
	dg(x+1,y),bz[x]=1,dg(x+1,y+c[x]),bz[x]=0;
}
int main()
{
	file("road");
	rd(n),rd(m),rd(k);
	rep(i,1,m) rd(b[i].u),rd(b[i].v),rd(b[i].w);
	rep(i,1,k)
	{
		rd(c[i]);
		rep(j,1,n) f[++t].u=j,f[t].v=i+n,rd(f[t].w);
	}
	sort(f+1,f+t+1,cmp);
	sort(b+1,b+m+1,cmp);
	rep(i,1,n) fa[i]=i;
	rep(i,1,m) if(fd(b[i].u)!=fd(b[i].v))
		d[++h]=b[i],fa[fd(b[i].u)]=fd(b[i].v);
	dg(1,0);
	printf("%lld",z);
	return 0;
}
