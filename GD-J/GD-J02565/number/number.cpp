#include <bits/stdc++.h>
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string in;
	std::cin >> in;
	std::vector<int> aop;
	aop.reserve(in.length());
	for(int a = 0;a < in.length();a++)
	{
		aop.push_back(in[a]);
	}
	std::sort(in.begin(),in.end());
	for(int i = aop.size()-1;i >= 0;i++)
	{
		std::cout << in[i];
	}
	return 0;
}
