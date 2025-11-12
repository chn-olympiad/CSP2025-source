#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node 
{
	int a,b,c,id,zd,vis,maxx;
}r[N];
int t,n,c1,c2,c3,f1,f2,f3;
bool cmp(node x,node y)
{
	return x.maxx > y.maxx;
}
void work()
{
	cin >> n;
	for (int i = 1;i<=n;i++)
	{
		cin >> r[i].a >> r[i].b >> r[i].c;
		r[i].id = i;
		if (r[i].a > r[i].b && r[i].a > r[i].c)
		{
			r[i].zd = 1;
			r[i].maxx = r[i].a;
			c1++;
		}
		else if (r[i].b > r[i].c && r[i].b > r[i].a)
		{
        	r[i].zd = 2;
			r[i].maxx = r[i].b;
			c2++;
		}
		else
		{
		    r[i].zd = 3;
			r[i].maxx = r[i].c;
			c3++;
		}
	}
	sort(r+1,r+n+1,cmp);
	for (int i = 1;i<=n;i++)
	{
		if (r[i].zd == 1)
		{
			if (f1==n/2)
			{
				if (r[i].b > r[i].c)
				{
					if (f2 == n/2)
					{
						f3++;
						r[i].vis = 3;
					}
					else
					{
						f2++;
						r[i].vis = 2;
					}
				}
				else
				{
					if (f3 == n/2)
					{
						f2++;
						r[i].vis = 2;
					}
					else
					{
						f3++;
						r[i].vis = 3;
					}
				}
			}
			else
			{
				f1++;
				r[i].vis = 1;
			}
		}
		else if (r[i].zd == 2)
		{
			if (f2==n/2)
			{
				if (r[i].a > r[i].c)
				{
					if (f1 == n/2)
					{
						f3++;
						r[i].vis = 3;
					}
					else
					{
						f1++;
						r[i].vis = 1;
					}
				}
				else
				{
					if (f3 == n/2)
					{
						f1++;
						r[i].vis = 1;
					}
					else
					{
						f3++;
						r[i].vis = 3;
					}
				}
			}
			else
			{
				f2++;
				r[i].vis = 2;
			}
		}
		if (r[i].zd == 3)
		{
			if (f3==n/2)
			{
				if (r[i].b > r[i].a)
				{
					if (f2 == n/2)
					{
						f1++;
						r[i].vis = 1;
					}
					else
					{
						f2++;
						r[i].vis = 2;
					}
				}
				else
				{
					if (f1 == n/2)
					{
						f2++;
						r[i].vis = 2;
					}
					else
					{
						f1++;
						r[i].vis = 1;
					}
				}
			}
			else
			{
				f1++;
				r[i].vis = 3;
			}
		}
	}
	int sum = 0;
	for (int i = 1;i<=n;i++)
	{
		if (r[i].vis == 1)
		    sum+=r[i].a;
		else if (r[i].vis == 2)
		    sum+=r[i].b;
		else
		    sum+=r[i].c; 
	}
	cout << sum << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        work();
	}
	return 0;
}

