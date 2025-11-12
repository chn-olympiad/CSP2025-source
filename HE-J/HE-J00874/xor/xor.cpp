#include <bits/stdc++.h>
using namespace std;
int v[500005];
int n, k;
int x(int l, int r)
{
	int sum = v[l];
	for (int i = l + 1; i <= r; i++)
	{
		sum ^= v[i];
	}
	return sum;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	return 0;
}
