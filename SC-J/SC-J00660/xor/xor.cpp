#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long long n, k, a[500000], cnt;
vector<long long> v[500000];
vector<pair<int, int>> res;

bool mycmp(pair<int, int> a, pair<int, int> b) {
	return (a.second - a.first) < (b.second - b.first);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for(int i = 0; i < n; i++) {
		v[i].push_back(a[i]);
		if(a[i] == k) res.push_back(make_pair(i + 1, i + 1)); 
		for(int j = 0; j < i && i != 0; j++) {
			long long t = v[i - 1][j] ^ a[i];
			v[i].push_back(t);
			if(t == k) {
				res.push_back(make_pair(i - j, i + 1));
			}
		}
	}
	sort(res.begin(), res.end(), mycmp);

	for(int i = 0; i < res.size(); i++) {
		bool f = 1;
		for(int j = 0; j < i; j++) {
			if(res[i].first >= res[j].first && res[i].first <= res[j].second
			|| res[i].second >= res[j].first && res[i].second <= res[j].second
			|| res[i].second >= res[j].second && res[i].first <= res[j].first) {
				res.erase(res.begin() + i);
				i--, f = 0;
				break;
			}
		}
		if(f) cnt++;
	}
	sort(res.begin(), res.end());
	cout << cnt;
	return 0;
} 