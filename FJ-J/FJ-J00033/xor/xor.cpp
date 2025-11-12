#include<bits/stdc++.h>
using namespace std;
int n, k, a[500001], s, p = 1, x;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i], x = 0;
		for(int j = i; j >= p; j--)
		{
			x ^= a[j];
			if(x == k)
				s++, p = i + 1;
		}
	}
	cout << s;
	
	return 0;
}
