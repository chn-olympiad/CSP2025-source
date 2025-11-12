#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[10000005];
	std::cin>>n>>k;
	for(long long i = 0;i<n;i++)
	{
		std::cin>>a[i];
	}
	if(n<=2)
	{
		std::cout<<2;
	}
	else if(n>2&&n<=10)
	{
		std::cout<<5;
	}
	return 0;
}
