#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct E
{
	ll x,y;
	ll w;
}e[1000005],d[20005];
E s[25][20005];
ll n,m,k,f[20005],cd[25];
ll c[25];
void read(ll &x)
{
	x=0;
	ll f=1;
	char c=getchar(); 
	while(c<'0'||'9'<c)
	{
		if(c=='-') f=-1;
		c=getchar(); 
	}
	while('0'<=c&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar(); 
	}
	x=x*f;
}
struct AC
{
	ll id,z;
}a[15][10005];
bool cmp(E a,E b){return a.w<b.w;}
bool cmp2(AC a,AC b){return a.z<b.z;}
ll find(ll x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void Kus()
{
	for(ll i=1;i<=n+k;i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	ll r=0;
	for(ll i=1;i<=m;i++)
	{
		ll x=e[i].x,y=e[i].y;
		ll p1=find(x),p2=find(y);
		if(p1!=p2)
		{
			s[0][++r]=e[i];
			f[p1]=p2;
		}
	}
}
ll ans=1e16;
ll q;
void dfs(ll x,ll sum,ll ls)
{
	if(x>k)
	{
		for(ll i=1;i<=cd[ls];i++)
		{
			sum+=s[ls][i].w;
		}
		ans=min(ans,sum);
	}
	else
	{
		dfs(x+1,sum,ls);
		ll i=1,j=1,p=0;
		while(i<=cd[ls]&&j<=n)//O(n)
		{
			if(s[ls][i].w<a[x][j].z)
			{
				q++;
				d[++p]=s[ls][i],i++;
			}
			else
			{
				q++;
				d[++p].x=n+x,d[p].y=a[x][j].id,d[p].w=a[x][j].z;
				j++;
			}
		}
		while(i<=cd[ls]) q++,d[++p]=s[ls][i],i++;
		while(j<=n)
		{
			q++;
			d[++p].x=n+x,d[p].y=a[x][j].id,d[p].w=a[x][j].z;
			j++;
		}
		for(ll i=1;i<=n+k;i++) f[i]=i;
		ll r=0;
		for(ll i=1;i<=p;i++)//O(n)
		{
			q++;
			ll X=d[i].x,Y=d[i].y;
			ll p1=find(X),p2=find(Y);
			if(p1!=p2)
			{
				s[x][++r]=d[i];
				f[p1]=p2;
			}
		}
		cd[x]=r;
		dfs(x+1,sum+c[x],x);
		cd[x]=0;
	}
}
int main()
{
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	read(n),read(m),read(k);
	for(ll i=1;i<=m;i++)
	{
		read(e[i].x),read(e[i].y),read(e[i].w); 
	}
	Kus();
	for(ll i=1;i<=k;i++)
	{
		read(c[i]);
		for(ll j=1;j<=n;j++) read(a[i][j].z),a[i][j].id=j;
		sort(a[i]+1,a[i]+n+1,cmp2);
	}
	cd[0]=n-1;
	dfs(1,0,0);
	printf("%lld",ans);
}
