#include <bits/stdc++.h>
using namespace std;
int t,ans;
struct k
{
	int a,b,c,mi,ma,l,s;
}m[100005];
int p[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			cin >> m[i].a >> m[i].b >> m[i].c;
			m[i].ma=max(max(m[i].a,m[i].b),max(m[i].b,m[i].c));
			m[i].mi=m[i].ma-(m[i].a+m[i].b+m[i].c-min(min(m[i].a,m[i].b),min(m[i].b,m[i].c))-m[i].ma);
			if(m[i].ma == m[i].a)
			{
				m[i].l=1;
			}
			else if(m[i].ma == m[i].b)
			{
				m[i].l=2;
			}
			else
			{
				m[i].l=3;
			}
			if(m[i].mi == m[i].a)
			{
				m[i].s=1;
			}
			else if(m[i].mi == m[i].b)
			{
				m[i].s=2;
			}
			else
			{
				m[i].s=3;
			}
		}
		for(int i=1; i<=n; i++)
		{
			ans+=m[i].ma;
			p[m[i].l]++;
		}
		while(p[1]>n/2||p[2]>n/2||p[3]>n/2)
		{
			if(p[1]>n/2)
			{
				while(p[1]!=n/2)
				{
					int j = 1e7,d;
					for(int i=1; i<=n; i++)
					{
						if(m[i].l==1 && m[i].mi<=j)
						{
							j = m[i].mi;
							d = m[i].s;
						}
					}
					ans-=j;
					p[1]--;
					p[d]++;
				}
			}
			if(p[2]>n/2)
			{
				while(p[2]!=n/2)
				{
					int j = 1e7,d;
					for(int i=1; i<=n; i++)
					{
						if(m[i].l==2&&m[i].mi<=j)
						{
							j = m[i].mi;
							d = m[i].s;
						}
					}
					ans-=j;
					p[2]--;
					p[d]++;
				}
			}
			if(p[3]>n/2)
			{
				while(p[3]!=n/2)
				{
					int j = 1e7,d;
					for(int i=1; i<=n; i++)
					{
						if(m[i].l==3&&m[i].mi<=j)
						{
							j = m[i].mi;
							d = m[i].s;
						}
					}
					ans-=j;
					p[3]--;
					p[d]++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
 } 