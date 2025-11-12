#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int const M = 998244353;
ll n, a[5005], mx[5005][5005], cnt[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i], cnt[i] = cnt[i - 1] + a[i];
	
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			mx[i][j] = max(mx[i][j - 1], a[j]);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 2; j <= n; j++) {
			if(cnt[j] - cnt[i - 1] > mx[i][j] * 2) ans++;
		}
	}
	cout << (ans % M);
	return 0;
}

