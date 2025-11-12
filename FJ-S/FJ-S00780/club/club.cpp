#include<bits/stdc++.h>
using namespace std;

struct int1
{
	int a;
	int b;
	int c;
};
int1 a[100000];
int1 b;
int ans;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int n;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c)
			{
				if(b.a<=(n/2))
				{
					b.a++;
					ans+=a[i].a;
				}
				else if(a[i].b>a[i].c)
				{
					if(b.b<=(n/2))
					{
						b.b++;
						ans+=a[i].b;
					}
				}
				else
				{
					if(b.c<=(n/2))
					b.c++;
					ans+=a[i].c;
				}
			}
			else if(a[i].b>a[i].a&&a[i].b>a[i].c)
			{
				if(b.b<=(n/2))
				{
					b.b++;
					ans+=a[i].b;
				}
				else if(a[i].a>a[i].c)
				{
					if(b.a<=(n/2))
					{
						b.a++;
						ans+=a[i].a;
					}
				}
				else
				{
					b.c++;
					ans+=a[i].c;
				}
			}
			else
			{
				if(b.c<=(n/2))
				{
					b.c++;
					ans+=a[i].c;
				}
				else if(a[i].a>a[i].b)
				{
					if(b.a<=(n/2))
					{
						b.a++;
						ans+=a[i].a;
					}
				}
				else
				{
					b.b++;
					ans+=a[i].b;
				}
			}
	    }
	    cout<<ans<<endl<<endl;
	    ans=0;
	    b.a=0;
	    b.b=0;
	    b.c=0;
	}	
	return 0;
 } 
