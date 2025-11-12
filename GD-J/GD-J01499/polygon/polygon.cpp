#include<bits/stdc++.h>
using namespace std;
int n,p[5005]={};
long long j(int a)
{
	if(a==0) return 1;
	return a*j(a-1);
}
long long c(int n,int m)
{
	long long a=j(n);
	long long b=j(m);
	long long c=j(n-m);
	return a/(b*c);
}
long long allsum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long unans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=3;i<=n;i++)
	{
		allsum+=c(n,i);
		for(int j=1;j<=n;j++)
		{
			int sum=0,max=0;
			for(int g=j;g<j+i;j++)
			{
				sum+=p[g];
				if(p[g]>max) max=p[g];
			}
			if(sum<max*2) ++unans;
		}
	}
	cout<<(allsum-unans)%998224353;
	return 0;
}
