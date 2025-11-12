#include <iostream>
#include <algorithm> 
using namespace std;
int n, k;
int a[500005];
int tag[2000005];
int sum[500005];
int ans;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	tag[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = (sum[i - 1] ^ a[i]);
		if (tag[(sum[i] ^ k)] == ans + 1)
		{
//			cout << (sum[i] ^ k) << "?\n"
//			cout << i << '\n';
			ans++;
		}
		tag[sum[i]] = ans + 1;
	}
	cout << ans;
}
