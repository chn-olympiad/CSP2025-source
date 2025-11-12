#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,u,v,w;
long long ans,cnt;

struct Edge
{
	int a,b,c,d,maxnum,id;
}e[N];

bool cmpaa(Edge x,Edge y)
{
	return x.c>y.c;
}

bool cmpab(Edge x,Edge y)
{
	return x.b>y.b;
}

bool cmpac(Edge x,Edge y)
{
	return x.a>y.a;
}

bool cmpb(Edge x,Edge y)
{
	return x.d>y.d;
}

bool cmp(Edge x,Edge y)
{
	return x.maxnum>y.maxnum;
}

void dfs(int k)
{
	if (k>n)
	{
		ans=max(cnt,ans);
		return;
	}
	if (u<n/2)
	{
		cnt+=e[k].a;
		u++;
		dfs(k+1);
		if (u<=n/2)
		{
			cnt-=e[k].a;
			u--;
		}
	}
	if (v<n/2)
	{
		cnt+=e[k].b;
		v++;
		dfs(k+1);
		if (v<=n/2) 
		{
			cnt-=e[k].b;
			v--;
		}
	}
	if (w<n/2)
	{
		cnt+=e[k].c;
		w++;
		dfs(k+1);
		if (w<=n/2)
		{
			cnt-=e[k].c;
			w--;
		}
	}
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool flagaa=true,flagab=true,flagac=true,flagb=true;
		for(int i=1;i<=n;i++)
		{
			cin>>e[i].a>>e[i].b>>e[i].c;
			e[i].d=e[i].a-e[i].b;
			e[i].maxnum=max(e[i].a,max(e[i].b,e[i].c));
			if (e[i].a==e[i].maxnum)
			{
				e[i].id=1;
			}
			else if (e[i].b==e[i].maxnum)
			{
				e[i].id=2;
			}
			else
			{
				e[i].id=3;
			}
			if (e[i].a!=0||e[i].b!=0)
			{
				flagaa=false;
			}
			if (e[i].a!=0||e[i].c!=0)
			{
				flagab=false;
			}
			if (e[i].b!=0||e[i].c!=0)
			{
				flagac=false;
			}
			if (e[i].c!=0)
			{
				flagb=false;
			}
		}
		if (flagaa)
		{
			sort(e+1,e+n+1,cmpaa);
			for(int i=1;i<=n/2;i++)
			{
				ans+=e[i].c;
			}
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		if (flagab)
		{
			sort(e+1,e+n+1,cmpab);
			for(int i=1;i<=n/2;i++)
			{
				ans+=e[i].b;
			}
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		if (flagac)
		{
			sort(e+1,e+n+1,cmpac);
			for(int i=1;i<=n/2;i++)
			{
				ans+=e[i].a;
			}
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		if (flagb)
		{
			sort(e+1,e+n+1,cmpb);
			for(int i=1;i<=n/2;i++)
			{
				ans+=e[i].a;
			}
			for(int i=n/2+1;i<=n;i++)
			{
				ans+=e[i].b;
			}
			cout<<ans<<"\n";
			ans=0;
			continue;
		}
		if (n<=10)
		{
			dfs(1);
			cout<<ans<<"\n";
			ans=0;
			cnt=0;
			u=0;
			v=0;
			w=0;
			continue;
		}
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if (e[i].id==1)
			{
				if (u<n/2)
				{
					ans+=e[i].a;
					u++;
				}
				else
				{
					if (e[i].b>=e[i].c&&v<n/2)
					{
						ans+=e[i].b;
						v++;
					}
					else
					{
						ans+=e[i].c;
						w++;
					}
				}
			}
			if (e[i].id==2)
			{
				if (v<n/2)
				{
					ans+=e[i].b;
					v++;
				}
				else
				{
					if (e[i].a>=e[i].c&&u<n/2)
					{
						ans+=e[i].a;
						u++;
					}
					else
					{
						ans+=e[i].c;
						w++;
					}
				}
			}
			if (e[i].id==3)
			{
				if (w<n/2)
				{
					ans+=e[i].c;
					w++;
				}
				else
				{
					if (e[i].a>=e[i].b&&u<n/2)
					{
						ans+=e[i].a;
						u++;
					}
					else
					{
						ans+=e[i].c;
						v++;
					}
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
		u=0;
		v=0;
		w=0;
	}
	return 0;
}
