#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	std::cin>>n;
	std::vector<int>a(n);
	for(auto&i:a)
	{
		std::cin>>i;
	}
	if(n<3)
	{
		std::cout<<0;
		return 0;
	}
	else if(n==3)
	{
		int max=0,sum=0;
		for(auto&i:a)
		{
			max=std::max(max,i);
			sum+=i;
		}
		if(sum>max*2)
		{
			std::cout<<1;
		}
		else
		{
			std::cout<<0;
		}
	}
}
