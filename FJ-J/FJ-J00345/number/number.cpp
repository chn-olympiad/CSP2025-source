#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::string s;
	long long a[1000005] = {0};
	std::cin>>s;
	for(long long i = 0;i<s.size();i++)
	{
		a[s[i]]++;
	}
	
	int i = 57;
	while(i>=48)//"0" = 48
	{
		for(long long j = 0;j<a[i];j++)
		{
			std::cout<<i-48;
		}
		i--;
	}

	return 0;
}
