#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005], pre[500005], dp[500005];
int cnt;
vector<pair<int, int> >v;
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	cin >> a[1];
	pre[1] = a[1];
	for(int i = 2; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			int x = pre[r] ^ pre[l - 1];
			if(x == k)v.push_back({l, r});
		}
	}
	int tot = v.size();
	sort(v.begin(), v.end());
	cnt = 1;
	dp[0] = 1;
	int maxi = 0;
	for(int i = 1; i < tot; i++){
		for(int j = 1; j < i; j++){
			if(v[j].second < v[i].first)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxi = max(dp[i], maxi);
	}
	cout << maxi;
}
