#include<iostream>
#include<algorithm>
long long c = 0;
int n,a[5001];
void az(int g,int all,int max,int k)
{
	if(g >= 3 && all > max * 2)
	{
		c++;
		c %= 998244353;
	}
	for(int i = k;i <= n;i++)
	{
		az(g + 1,all + a[i],a[i],i + 1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	for(int i = 1;i <= n;i++)
	{
		std::cin>>a[i];
	}
	std::sort(a + 1,a + 1 + n);
	// g all max i
	az(0,0,0,1);
	std::cout<<c;
	return 0;
}
