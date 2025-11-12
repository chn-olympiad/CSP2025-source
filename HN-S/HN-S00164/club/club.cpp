#include <bits/stdc++.h>
using namespace std;	
int a,b,c;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,sum=0;
		cin>>n;
		int a1=0,b1=0,c1=0;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			if(a1>=n/2)
			{
				a=0;
			}
			if(b1>=n/2)
			{
				b=0;
			}
			if(c1>=n/2)
			{
				c=0;
			}
			if(c>a&&c>b)
			{	
				sum+=c;
				c1++;
			}
			if(a>c&&a>b)
			{
				a1++;
				sum+=a;
			}
			if(b>a&&b>c)
			{
				b1++;
				sum+=b;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
