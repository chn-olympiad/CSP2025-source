#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, k, ans, last;
ll sum[N];
unordered_map<ll, bool> cnt;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	cnt[0] = 1;
	for(int i = 1, a;i <= n;i++)
	{
		cin >> a;
		sum[i] = sum[i - 1] ^ a;
		cnt[sum[i]] = 1;
		if(cnt[sum[i] ^ k])
		{
			for(int j = last;j < i;j++)
				if(sum[j] == (sum[i] ^ k))
				{
					ans++, last = i;
					break;
				}
		}
	}
	cout << ans << "\n";
	return 0;
}
