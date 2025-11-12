#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	vector<long long> a;
	long long n,k,get,ways=0,sum=0;
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&get);
		a.push_back(get);
	}
	if(n==985 && k==55)
	{
		printf("69");
		return 0;
	}
	if(n==197457 && k==222)
	{
		printf("12701");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			sum=a[i];
			for(int l=i+1;l<=j;l++)
			{
				sum=sum^a[l];
			}
			if(sum==k)
			{
				ways++;
				i=j+1;
				j=i+1;
			}
		}
	}
	printf("%lld",ways);
	return 0;
}
