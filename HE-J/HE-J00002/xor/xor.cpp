#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int n, k, a, ans;
set<int> vis;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	vis.insert(0);
	for (int i = 1, last = 0; i <= n; i++)
	{
		cin >> a;
		int sum = last ^ a;
		if (vis.count(k ^ sum)) 
		{
			ans++;
			vis.clear();
		}
		vis.insert(sum);
		last = sum;
	}
	cout << ans;
	return 0;
}
