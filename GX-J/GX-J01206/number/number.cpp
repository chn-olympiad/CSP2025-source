#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::string s;
	std::cin>>s;
	std::vector<int>v;
	v.reserve(s.size());
	for(auto&i:s)
	{
		if(std::isdigit(i))
		{
			v.push_back(i-'0');
		}
	}
	std::sort(v.begin(),v.end(),[](int const&x,int const&y){return x>y;});
	for(auto&i:v)
	{
		std::cout<<i;
	}
}
