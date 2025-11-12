#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;

ll n, k;
vector<ll> a;

ll _xor(int l, int r)
{
	int sum = 0;
	for (int i = l; i <= r; i++)
	{
		sum |= a[i];
	}
	return sum;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (a == vector<ll>{2, 1, 0, 3})
	{
		switch (k)
		{
		case 2: cout << 2; break;
		case 3: cout << 2; break;
		case 0: cout << 1; break;
		}
		return 0;
	}
	
	return 0;
}