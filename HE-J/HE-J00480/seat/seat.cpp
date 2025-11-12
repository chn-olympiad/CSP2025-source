#include<bits/stdc++.h>
using namespace std;
long long n,m,a[11100000],s,sum,v;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
	std::cin>>n>>m;
	std::cin>>a[1];
	sum=a[1];
	v=n*m;
	for(int i=2;i<=v;i++)
	{
		std::cin>>a[i];
	}
	std::sort(a+1,a+v+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==sum)
		{
			sum=i;
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			sum--;
			if(sum==0)
			{
				std::cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
