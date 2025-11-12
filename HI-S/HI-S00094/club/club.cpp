#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
struct bn
{
	long long ai[3];
};
bn a[100001];
long long n;
long long bnrs[3];



int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
int t;

cin>>t;
for(int q = 1;q <= t;q++)
{
	
	long long max1 = 0;
	
	cin>>n;
	for(long long i = 1;i <= n;i++)
	{
		for(long long j = 1;j <= 3;j++)
		{
			cin>>a[i].ai[j];
		}
		
	}
	
	for(long long k = 1;k <= n;)
	{
		long long max2 = -1;
		for(long long i = 1;i <= 3;i++)
		{
			for(long long j = 1;j <= 3;j++)
			{
				if(j == i)
				{
					continue;
				}
				if(max2 < a[k].ai[i] + a[k+1].ai[j])
				{
					max2 = a[k].ai[i] + a[k+1].ai[j];
				}
			}
		}
		k=k+2;
		max1 += max2;
		//cout<<max2<<" ";
	}
		
		
		
		
		
		
	
	cout<<max1;
}
	return 0;
}
