#include<bits/stdc++.h>
using namespace std;
int main()
{
	struct a
	{
		int a,b,c;
	}a[100005];
	struct b
	{
		bool a,b,c;
	}best[100005];
	int e=0,k[5]={0};
	freopen("club.in","e",stdin);
	for(int x=1;x<=e;x++)
	{
		int n,a1=0,a2=0,a3=0,ans=0;
		freopen("club.in","n",stdin);
		for(int i=1;i<=n;i++)
		{
			freopen("club.in","a[i].a",stdin);
			freopen("club.in","a[i].b",stdin);
			freopen("club.in","a[i].c",stdin);
			if(a[i].a>a[i].b&&a[i].a>a[i].c)
			{
				best[i].a=1;
				if(a1<(n/2))
				{
					ans+=a[i].a;
					a1++;
				}
			}
			else if(a[i].b>a[i].c&&a[i].b>a[i].a)
			{
				best[i].b=1;
				if(a2<(n/2))
				{
					a2++;
					ans+=a[i].b;
				}
			}
			else
			{
				best[i].c=1;
				if(a3<(n/2))
				{
					a3++;
					ans+=a[i].c;
				}
			}
		}
		k[x]=ans;
	}
	for(int i=1;i<=e;i++)
	freopen("club.out","k[i]",stdout);
	return 0;
}

