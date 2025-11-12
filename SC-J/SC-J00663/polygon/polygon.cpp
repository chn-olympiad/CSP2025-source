#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[5005];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false); //减少输入输出用时
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (n != 3)
		{
			if (i <= n-3)
			{
				ans += i;
			}
		}
		
	}
	if (n == 3)
	{
		int x = max(a[1], max(a[2], a[3]));
		if (a[1] + a[2] + a[3] - x > x)
		{
			ans = 1;
		}
	}
	
	cout << ans % 998244353;
	return 0;
}