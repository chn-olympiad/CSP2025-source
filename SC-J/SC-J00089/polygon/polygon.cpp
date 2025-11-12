#include<bits/stdc++.h>
using namespace std;
long long n,da,gs;
int sr[50000+5];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sr[i];
		if(sr[i]==1)
		gs++;
	}
	if(gs==n)
	{
		long long s=(n*(n-1)*(n-2))%998224353;
		cout<<s;
	}
	else
	{
		if(n<3)
		{
			cout<<'0';
			return 0;
		}
		else if(n==3)
		{
			int max1=0,pds=0;
			for(int i=1;i<=3;i++)
			{
				max1=max(max1,sr[i]);
				pds+=sr[i];
			}
			if(pds>max1)
			{
				cout<<'1';
				return 0;
			}
			else
			{
				cout<<'0';
				return 0;
			}
		}
	}
	return 0;
} 