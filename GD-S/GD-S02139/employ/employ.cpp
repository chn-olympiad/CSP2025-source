#include <bits/stdc++.h>

int mod = 998244353;
long long ans = 1; 

using namespace std;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	string s;
	vector<int> c(n);
	
	cin >> n >> m;
	cin >> s;
	
	for(int i = 0; i < n; i++)
		cin >> c[i];

	for(int i = 2; i < n; i++)
		ans = ans * i % mod;
	
	cout << ans;
	
	return 0;
}
