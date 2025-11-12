#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[100005], num, num1;
signed main()
{
	freopen("xor.in", "r", "std::cin");
	freopen("xor.out", "w", "std::cout");
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		num1 ^= a[i];
		if (num1 == k)
		{
			num++;
			num1 = 0;
		}
	}
	
	cout << num; 
	return 0;
	
}
