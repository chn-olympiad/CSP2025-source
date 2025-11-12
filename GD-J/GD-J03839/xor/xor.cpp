#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
long long n, k; 
long long num_list[maxn];
vector<pair<long long, long long>> ares;
long long cnt = 0;
long long ans = 0;

bool cmp (pair<long long, long long> prev, pair<long long, long long> next) {
	if (prev.second < next.second) return true;
	else if (prev.second == next.second) if (prev.first > next.first) return true;
	return false;
}

int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> num_list[i];
	for (int i = 0; i < n; i++) {
		long long sum;
		sum = num_list[i];
		if (sum == k) {
			ares.push_back({ i, i });
			cnt++;
			continue;
		}
		if (i >= 1 && num_list[i] == num_list[i - 1]) {
			if (ares[ares.size() - 1].first == ares[cnt - 1].second) 
				ares.push_back({ i, i });
			else
				ares.push_back({ i, ares[cnt - 1].second });
			cnt++;
		}
		if (i < n - 1) {
			for (int j = i + 1; j < n; j++) {
				long long sum2;
				sum2=sum ^ num_list[j];
				if (sum2 == k) {
					ares.push_back({i, j});
					cnt++;
					break;
				}
			}
		}
	}
	if (cnt <= 1) {
		cout << cnt << "\n";
		return 0;
	}
	sort(ares.begin(), ares.end(), cmp);
	long long cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = cnt2; j < cnt; j++) {
			if (i <= ares[j].first) {
				ans++;
				i=ares[j].second + 1;
				if (i == n) {
					cout << ans << "\n";
					return 0;
				}
				cnt2=j + 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
