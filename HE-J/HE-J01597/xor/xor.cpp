#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e5+10;
ll n,k;
ll a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	int temp = 0;
	for (int i = 1,X;i <= n;i++)
	{
		cin >> X;
		if (X == 0)
		{
			continue;
		}
		if (X == 1)
		{
			temp++;
			a[temp] = X;
		}
	}
	n = temp;
	if (k == 0)
	{
		if (n % 2 == 1)
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << n / 2;
			return 0;
		}
	}
	if (k == 1)
	{
		cout << n;
	}
	return 0;
}
