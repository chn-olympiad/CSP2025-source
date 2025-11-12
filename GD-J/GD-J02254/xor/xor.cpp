#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, k, cnt;
int a[maxn];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i];
    	if (a[i] == 1) cnt++;
	}
	if (k == 0) cout << cnt / 2;
	else if (k == 1) cout << cnt;
	return 0;
}
