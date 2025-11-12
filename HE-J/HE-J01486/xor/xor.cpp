#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 66;
ll n, k, a[N], yih[N], lat1, lat2, ans;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("xor.in", "r", stdin);freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> a[i], yih[i] = yih[i - 1] ^ a[i];
	lat1 = lat2 = -1;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j <= n;j ++)
		{
			if((yih[j] ^ yih[i - 1]) == k)
			{
				if(i <= lat2 && (j - i + 1) >= (lat2 - lat1 + 1)) break;
				if(j <= lat2 && lat1 <= i) {lat1 = i, lat2 = j;break;}
				if(i > lat2) {lat1 = i, lat2 = j;ans ++;break;}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
