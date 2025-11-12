#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

const long long mod = 998244353;
const int N = 505;
int c[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	int sum = 0, all = n;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] <= sum)
		{
			all--;
			sum++;
		}
	}
	if(all < m)
	{
		printf("0\n");
		return 0;
	}
	long long ans = 1;
	for(int i = 2; i <= all; i++)
	{
		ans *= i;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
