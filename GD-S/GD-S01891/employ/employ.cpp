#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10, mod = 998244353;
int arr[N];
int main()
{
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	long long ans = 1;
	for(int i = 1; i <= 18; i++)
	{
		if(n-i <= 0) break;
		ans = (ans * (n - i)) % mod;
	}
	
	cout << ans;
	return 0;
}
