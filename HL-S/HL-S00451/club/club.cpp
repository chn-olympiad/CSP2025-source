#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long ans;
struct ppp{
	int a;
	int b;
	int c;
}g[N];
bool cmp(ppp a1,ppp b1)
{
	if (a1.a==b1.a)
	{
		if (a1.b==b1.b)
			return a1.c>b1.c;
		else
			return a1.b>b1.b;
	}
	return a1.a>b1.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		ans=0;
		cin>>n;
		int maxa=n/2;
		int maxb=n/2;
		int maxc=n/2;
		for (int i=1;i<=n;i++)
		{
			cin>>g[i].a>>g[i].b>>g[i].c;
		}
		sort(g+1,g+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			int maxn=max(max(g[i].a,g[i].b),g[i].c);
			int minn=min(min(g[i].a,g[i].b),g[i].c);
			if (maxn==g[i].a && maxa!=0)
			{
				maxa--;
				ans+=maxn;
			}
			else if (maxn==g[i].b && maxb!=0)
			{
				maxb--;
				ans+=maxn;
			}
			else if (maxn==g[i].c && maxc!=0)
			{
				maxc--;
				ans+=maxn;
			}
			else
			{
				if (maxa!=0)
				{
					ans+=g[i].a;
				}
				if (maxb!=0)
				{
					ans+=g[i].b;
				}
				if (maxc!=0)
				{
					ans+=g[i].c;
				}
			}
		}
		cout<<ans<<endl;
	}
}
