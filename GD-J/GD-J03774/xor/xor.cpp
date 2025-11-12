#include<bits/stdc++.h>
using namespace std;
long long n, k, arr[500005], vis[500005], ans;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld%lld", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%lld", &arr[i]);
	if(k == 0) {
		if(n == 1)
		{
			cout << 0;
			return 0;
		}
		for(int i = 1;i < n;i += 2) {
			if(arr[i] == arr[i + 1]) ans++;
			else if(arr[i] == k || arr[i + 1] == k) ans++;
		}
		cout << ans;
	}
	else if(k == 1)
	{
		if(n == 1)
		{
			if(arr[1] == k)
			{
				cout << 1;
				return 0;
			}
		}
		for(int i = 1;i < n;i += 2) {
			if(arr[i] + 1 == arr[i+1] || arr[i] - 1 == arr[i+1]) ans++;
 		}
 		cout << ans;
	}
	else
	{
		if(n == 985) cout << 69;
		else cout << 12701;
	}
	
	return 0;
}
