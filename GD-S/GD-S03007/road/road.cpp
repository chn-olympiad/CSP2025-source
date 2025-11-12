#include<bits/stdc++.h>
using namespace std;
long long n,S=1e18,m,k,b[100100],a[11][10010],h[100100],e[100100],T;
struct jg
{
	long long x,y,z;
}c[1000100];
struct gj
{
	long long x,y;
};
vector<gj>t[100100];
bool cp(jg a,jg b)
{
	return a.z<b.z;
}
int fi(int x)
{
	if(x==b[x])
	{
		return x;
	}
	b[x]=fi(b[x]);
	return b[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i].x>>c[i].y>>c[i].z;
	}
	sort(c+1,c+m+1,cp);
	for(int i=1;i<=n;i++)
	{
		b[i]=i;
	}
	int o=0;
	for(int i=1;i<=m;i++)
	{
		long long x=fi(c[i].x),y=fi(c[i].y);
		if(x!=y)
		{
			b[x]=y;
			c[++o]=c[i];
		}
	}
	m=o;
	o=0;
	for(int i=0;i<k;i++)
	{
		cin>>e[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			h[++o]=a[i][j];
		}
		//cout<<i<<' '<<k<<"\n";
	}
	sort(h+1,h+o+1);
	o=unique(h+1,h+o+1)-h-1;
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=lower_bound(h+1,h+o+1,a[i][j])-h;
		}
	}
	for(int x=0;x<(1<<k);x++)
	{
		long long s=0;
		for(int i=0;i<k;i++)
		{
			if(x&(1<<i))
			{
				s+=e[i];
				for(int j=1;j<=n;j++)
				{
					//cout<<i+1<<' '<<j<<' '<<h[a[i][j]]<<"\n";
					t[a[i][j]].push_back({i+1+n,j});
				}
			}
		}
		for(int i=1;i<=n+k;i++)
		{
			b[i]=i;
		}
		for(int i=1,j=1;i<=m;i++)
		{
			for(;j<=o&&h[j]<c[i].z;j++)
			{
				for(gj v:t[j])
				{
					int x=fi(v.x),y=fi(v.y);
					if(x!=y)
					{
						//cout<<x<<' '<<y<<' '<<h[j]<<"\n";
						b[x]=y;
						s+=h[j];
					}
				}
			}
			long long x=fi(c[i].x),y=fi(c[i].y),z=c[i].z;
			if(x!=y)
			{
				//cout<<x<<' '<<y<<' '<<z<<"\n";
				b[x]=y;
				s+=z;
			}
		}
		for(int i=1;i<=o;i++)
		{
			t[i].clear();
		}
		S=min(S,s);
	}
	cout<<S;
}
