#include <iostream>
using namespace std;
const int N = 5e5 + 5;
int n, s[N], k, a[N];
bool check(int sum, int l, int m)
{
	if(sum == m)
		return true;
	if(l == n)
		return false;
	for(int i = l + 1 ; i <= n ; i++)
	{
		for(int j = n ; j >= i ; j--)
		{
			if((s[j] ^ s[i - 1]) != k)
				continue;
			if(check(sum + 1, j, m))
				return true;
		}
	}
	return false;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d", &a[i]);
		s[i] = (s[i - 1] ^ a[i]);
	}
	int l = 1, r = n, m = (l + r) / 2;
	while(l < r)
	{
		if(check(0, 0, m))l = m;
		else r = m - 1;
		m = (l + r) / 2;
	}
	cout << l << "\n";
	return 0;
}
