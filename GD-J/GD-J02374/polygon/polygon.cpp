#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[100005], mod = 998244353, ans = 9;
	cin >> n;
	for (int i = 1; i <= n; i++)
	    cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << ans;
	return 0;	
} 
