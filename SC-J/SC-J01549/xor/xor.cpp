#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
int n, k;
int a[N + 5];
int pre[N + 5];

map<int, int> mp;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ a[i];
	int res = 0;
	mp[0] = 1;
	for(int r = 1; r <= n; r++)
	{
		int nd = pre[r] ^ k;
		if(mp.count(nd))
		{
			mp.clear();
			res++;
		}
		mp[pre[r]] = r + 1;
	}
	
	cout << res << '\n';

	return 0;
}