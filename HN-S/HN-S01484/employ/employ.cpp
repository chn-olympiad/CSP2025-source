#include <bits/stdc++.h>
using namespace std;
const int P = 998344535;
int n;
int main()
{
	freopen("employ.in", "r", stdin);	
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	long long int ans = 1;
	while (n--)
	{
		ans *= n, ans %= P;
	}
	cout << n;
	return 0;	
} 
