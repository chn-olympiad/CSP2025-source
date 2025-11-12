#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	if(n<3)
	{
		cout<<0;
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		exit(0);
	}
	else
	{
		int m=998244353;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long sum=0,ma=0;
				for(int x=i;x<=j;x++)
				{
					sum+=a[x];
					if(a[x]>ma)
					{
						ma=a[x];
					}
				}
				if(sum>ma*2)
				{
					cnt++;
					cnt%=m;
				}
			}	
		}
		cout<<cnt;
	}
}
