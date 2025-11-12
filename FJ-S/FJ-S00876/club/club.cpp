#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i = 1;i<=t;i++)
	{
		int n;
		cin>>n;
		if(n=2)
		{
			int a,b,c,aa,bb,cc,big = 0,bbig = 0;
			cin>> a,b,c;
			cin>>aa,bb,cc;
			if(a>b&&a>c)
			{
				big = a;
			}
			else
			{
				if(b>a&&b>c)
				{
					big = b;
				}
				else
				{
					if(c>a&&c>b)
					{
						big = c;
					}
				}
			}
			if(aa>bb&&aa>cc)
			{
				bbig = aa;
			}
			else
			{	
				if(bb>aa&&bb>cc)
				{
					bbig = bb;
				}
				else
				{
					if(cc>aa&&cc>>bb)
					{
						bbig = cc;
					}
				}
			}
			if(big ==a&&bbig==aa)
			{
				if(b>c&&b>bb&&b>cc)
				{
					big = b;
				}
				else
				{
					if(c>b&&c>bb&&c>cc)
					{
						big = c;
					}
				}
				if(bb>cc&&bb>b&&bb>c)
				{
					bbig = bb;
				}
				else
				{
					if(cc>bb&&cc>b&&cc>c)
					{
						bbig = cc;
					} 
				}
			}
			ans = bbig+big;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
