#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define ll long long
#define rint register int

using namespace std;
using namespace __gnu_pbds;

const int N=3e6+10,K=10+10;

int n,m,k,u,v;
ll w;

struct graph
{
	int u,v;
	ll w;
}arr[N],brr[N];

ll c[K];

map<int,map<int,ll> >a;

inline ll read()
{
	int k=0,f=1;
	char c=getchar();
	
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	
	while('0'<=c&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	
	return k*f;
}

inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x; 
	}
	
	if(x<10)
	{
		putchar(x+'0');
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
	
}

inline bool cmp(graph a,graph b)
{
	return a.w<b.w;
}

int pre[N];
inline int find(int x)
{
	if(x==pre[x])
	{
		return x;
	}
	
	return pre[x]=find(pre[x]);
}

inline ll kruskal()
{
	ll ans=0;
	
	for(rint i=1;i<=m;++i)
	{
		brr[i]=arr[i];
	}
	
	sort(brr+1,brr+m+1,cmp);
		
	for(rint i=1;i<=n+k;++i)
	{
		pre[i]=i;
	}
		
	for(rint i=1;i<=m;++i)
	{
		int u=brr[i].u,v=brr[i].v;
		ll w=brr[i].w;
		u=find(u),v=find(v);
			
		if(u==v)
		{
			continue;
		}
			
		pre[u]=v;
			
		ans=ans+1ll*w;
	}
	
	return ans;
}


int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	
	for(rint i=1;i<=m;++i)
	{
		u=read(),v=read(),w=read();
		arr[i]={u,v,w};
	}
	
	bool flag=1;
	
	for(rint i=1;i<=k;++i)
	{
		c[i]=read();
		if(c[i]!=0)
		{
			flag=0;
		} 
		
		for(rint j=1;j<=n;++j)
		{
			a[i][j]=read();
		}
	}
	
	ll ans=0;
	
	if(flag)
	{
		for(rint i=1;i<=k;++i)
		{
			for(rint j=1;j<=n;++j)
			{
				arr[++m]={n+i,j,a[i][j]}; 
			}
		}
		
		sort(arr+1,arr+m+1,cmp);
		
		for(rint i=1;i<=n+k;++i)
		{
			pre[i]=i;
		}
		
		for(rint i=1;i<=m;++i)
		{
			int u=arr[i].u,v=arr[i].v,w=arr[i].w;
			u=find(u),v=find(v);
			
			if(u==v)
			{
				continue;
			}
			
			pre[u]=v;
			
			ans=ans+1ll*w;
		}
		
		write(ans);
 	}
	 
	else if(k==0)
	{
		sort(arr+1,arr+m+1,cmp);
		
		for(rint i=1;i<=n+k;++i)
		{
			pre[i]=i;
		}
		
		for(rint i=1;i<=m;++i)
		{
			int u=arr[i].u,v=arr[i].v,w=arr[i].w;
			u=find(u),v=find(v);
			
			if(u==v)
			{
				continue;
			}
			
			pre[u]=v;
			
			ans=ans+1ll*w;
		}
		
		write(ans);
	}	
	
	else
	{
		ll ans=1e18,sm=m,cost=0;
	
		for(rint i=0;i<(1<<k);++i)
		{
			m=sm;
			for(rint j=0;j<k;++j)
			{
				if((i>>j)&1)
				{
					cost+=c[j+1];
					for(rint k=1;k<=n;++k)
					{
						arr[++m]={n+j+1,k,a[j+1][k]}; 
					}
				}
			}
			ans=min(ans,kruskal()+cost);
		}
		write(ans);
	}
	return 0;
}