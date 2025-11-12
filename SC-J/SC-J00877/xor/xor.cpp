#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10, I = 1e6 + 10;
int n, K, A[N], S[N], las[I];
vector <pair <int, int> > hav;

bool cmp(pair <int, int> a, pair <int, int> b) {
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int cnt;
pair <int, int> dp[N];

signed main() {
//	freopen("xor6.in", "r", stdin);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> K; S[0] = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> A[i];
		S[i] = S[i - 1] ^ A[i];
	}
	for(int i = 1; i < I; i ++) las[i] = -1;
	las[0] = 0;
	for(int i = 1; i <= n; i ++) {
		int wnt = K ^ S[i];
		if(-1 != las[wnt])  hav.push_back({las[wnt] + 1, i});
		
		las[S[i]] = i;
	}
//	sort(hav.begin(), hav.end(), cmp);
	
	dp[0] = {0, 0};
	for(int i = 0; i < hav.size(); i ++) {
//		cerr<<hav[i].first<<" "<<hav[i].second<<"\n";
		int l = 0, r = cnt, res = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(dp[mid].second < hav[i].first) res = mid, l = mid + 1;
			else r = mid - 1;
		}
//		cerr<<res<<"\n";
		
		if(cnt == res) dp[++ cnt] = {hav[i].first, hav[i].second};
		else if(hav[i].second < dp[res + 1].second) dp[res + 1] = {hav[i].first, hav[i].second};
	}
	cout << cnt;
	return 0;
}
