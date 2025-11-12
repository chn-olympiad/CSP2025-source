#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=10005,M=1000005,inf=9e18;
ll n,m,k,t[15][N],f[N],ans=0;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct node {
	ll a,b,c;
}pa[M];
bool cmp(node x,node y)
{
	return x.c<y.c;
}
ll find(ll x)
{
	while(x!=f[x])
	{
		x=f[x]=f[f[x]];
	}
	return x;
}
void kru(ll cnt,ll sum,ll ss)
{
	for(ll i=1;i<=n+sum;i++)
	{
		f[i]=i;
	}
	sort(pa+1,pa+m+cnt+1,cmp);
	ll cnt1=0,s=0;
	for(ll i=1;i<=m+cnt;i++)
	{
		if (find(pa[i].a)==find(pa[i].b))
		{
			continue;
		}
		ll x=pa[i].a,y=pa[i].b;
		f[x]=y;
		s+=pa[i].c;
		cnt1++;
		if (cnt1==n+sum-1)
		{
			break;
		}
	}
	for(ll i=1;i<=n+sum;i++)
	{
		f[i]=0;
	}
//	printf("%lld\n",s+ss);
	ans=min(ans,s+ss);
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++)
	{
		pa[i].a=read(),pa[i].b=read(),pa[i].c=read();
	}
	for(ll i=1;i<=k;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			t[i][j]=read();
		}
	}
	if (k==0)
	{
		for(ll i=1;i<=n;i++)
		{
			f[i]=i;
		}
		sort(pa+1,pa+m+1,cmp);
		ll cnt=0;
		for(ll i=1;i<=m;i++)
		{
			if (find(pa[i].a)==find(pa[i].b))
			{
				continue;
			}
			ll x=pa[i].a,y=pa[i].b;
			f[x]=y;
			ans+=pa[i].c;
			cnt++;
			if (cnt==n-1)
			{
				break;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	ans=inf;
	for(ll w=0;w<=(1ll<<k)-1ll;w++)
	{
		ll p=w,idx=0,cnt=0,sum=0,ss=0;
		while(p)
		{
			idx++;
			if (p&1ll)
			{
				sum++;
				ss+=t[idx][0];
				for(ll i=1;i<=n;i++)
				{
					cnt++;
					pa[m+cnt]=(node){i,n+sum,t[idx][i]};
				}
			}
			p>>=1ll;
		}
//		printf("%lld %lld %lld ",cnt,sum,ss);
		kru(cnt,sum,ss);
		for(ll i=1;i<=cnt;i++)
		{
			pa[m+i]=(node){0,0,0};
		}
		//cnt±ß,sumµã,ssÖµ 
	}
	printf("%lld",ans);
	return 0;
}
