#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10, mod = 998244353;
using ll = long long;

int n, arr[N];
bool pf = true;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if(arr[i] != 1) pf = false;
	}
	if(pf)
	{
		int ans = 0;
		for(int i = 3; i <= n; i++)
		{
			int a = 1, b = 1;
			for(int j = n-i+1; j <= n; j++)
			{
				a = (a * j) % mod;
			}
			for(int j = i; j >= 1; j--)
			{
				b = (b * j) % mod;
			}
			ans += (a / b);
		}
		cout << ans;
		return 0;
	}
	else if(n == 3)//pf
	{
		int a = arr[1], b = arr[2], c = arr[3], sum = a + b + c, maxn = max(max(a, b), c) * 2;
		if(sum > maxn) cout << 1;
		else cout << 0;
	}
	return 0;
}
