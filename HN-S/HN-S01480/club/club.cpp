#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a,b;
}x[100010];
struct node1{
	int a,b,c;
}xx;
bool cmp(node p,node q)
{
	if (p.a>q.a)
	{
		return true;
	}
	else if (p.a==q.a)
	{
		if (p.b<=q.b)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int hyx=1;hyx<=t;hyx++)
	{
		int n,a[100010],b[100010],c[100010];
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		sort(c+1,c+n+1);
		if (c[n]==0)
		{
			for(int i=1;i<=n;i++)
			{
				c[i]=b[i];
			}
			sort(c+1,c+n+1);
			if (c[n]==0)
			{
				sort(a+1,a+n+1);
				long long s=0;
				for(int i=n;i>n/2;i--)
				{
					s+=a[i];
				}
				cout<<s<<endl;
			}
			else
			{
				long long s=0;
				for(int i=1;i<=n;i++)
				{
					x[i].a=a[i];
					x[i].b=b[i];
				}
				sort(x+1,x+n+1,cmp);
				for(int i=1;i<=n/2;i++) s+=x[i].a;
				for(int i=n;i>n/2;i++) s+=x[i].b;
				cout<<s<<endl;
			}
		}
		else
		{
			int n,a=0,b=0,c=0,sa=0,sb=0,sc=0;
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				node1 xx;
				cin>>xx.a>>xx.b>>xx.c;
				int maxx=max(xx.a,max(xx.b,xx.c));
				if (maxx==xx.a)
				{
					if (a<n/2)
					{
						a++;
						sa+=xx.a;
					}
					else
					{
						maxx=max(xx.b,xx.c);
						if (maxx==xx.b)
						{
							b++;
							sb+=xx.b;
						}
						else
						{
							c++;
							sc+=xx.c;
						}
					}
				}
				else if (maxx==xx.b)
				{
					if (b<n/2)
					{
						b++;
						sb+=xx.b;
					}
					else
					{
						maxx=max(xx.a,xx.c);
						if (maxx==xx.a)
						{
							a++;
							sa+=xx.a;
						}
						else
						{
							c++;
							sc+=xx.c;
						}
					}
				}
				else
				{
					if (c<n/2)
					{
						c++;
						sc+=xx.c;
					}
					else
					{
						maxx=max(xx.b,xx.a);
						if (maxx==xx.a)
						{
							a++;
							sa+=xx.a;
						}
						else
						{
							b++;
							sb+=xx.b;
						}
					}
				}
			}
			cout<<sa+sb+sc<<endl;
		}
	}
	return 0;
}
