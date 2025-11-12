#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[1005], b[1005];  
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k; 
//	cerr << k << "\n"; 
	b[0] = 0; 
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		b[i] = a[i] ^ b[i - 1]; 
	}
	for(int i = 1; i <= n; i++)
	{
		int left = i, tmp = 0; 
		for(int j = i; j <= n; j++)
		{
//			cerr << (b[j] ^ b[left - 1]) << " " << b[j] << " " << b[left - 1] << " " << j << " " << (left) << "\n"; 
			if((b[j] ^ b[left - 1]) == k) tmp++, left = j + 1; 
		}
		ans = max(ans, tmp); 
	}
//	cerr << "\n"; 
	cout << ans; 
	return 0; 
}

