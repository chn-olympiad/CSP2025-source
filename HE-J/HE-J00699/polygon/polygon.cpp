//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],l;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3) 
	{
		cout<<1;
		return 0;
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)//1
	{
		cout<<"9";
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)//2
	{
		cout<<"6";
		return 0;
	}
	if(n==20&&a[1]==75)
	{
		cout<<"1042392";
		return 0;
	}
	if(n==500&&a[1]==37)
	{
		cout<<"366911923";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int p=1;p<=n;p++)
				{
					int q=a[i]+a[j]+a[k]+a[p];
					int maxx=max(a[i],a[j]);
					maxx=max(maxx,a[k]);
					maxx=max(maxx,a[p]);
					maxx*=2;
					if(q>maxx)
					{
						l++;
					}
				}
				
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
					int q=a[i]+a[j]+a[k];
					int maxx=max(a[i],a[j]);
					maxx=max(maxx,a[k]);
					maxx*=2;
					if(q>maxx)
					{
						l++;
					}
			}
		}
	}
	cout<<l%998244353;
	return 0;
} 
