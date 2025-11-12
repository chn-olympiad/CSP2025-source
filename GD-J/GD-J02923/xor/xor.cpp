#include <iostream>
#include <cstdio>
#include <map>
#define int long long
using namespace std;

int a[500010], b[500010], f[500010];
map<int, int> mp, vis;

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	vis[0] = 1, mp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		int sl = b[i] ^ k;
		if(vis[sl]) f[i] = max(f[i], f[mp[sl]] + 1);
		vis[b[i]] = 1, mp[b[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans << '\n'; 
	
	fclose(stdin); fclose(stdout);
	return 0;
}
