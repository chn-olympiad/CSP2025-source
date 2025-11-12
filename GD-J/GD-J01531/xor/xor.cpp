#include <bits/stdc++.h>
using namespace std;
int sum[500005], a[500005];
bool f[500005];
bool cmp(pair<int, int> x, pair<int, int> y){
	if (x.second - x.first + 1 == y.second - y.first + 1){
		if (x.first == y.first){
			return x.second < y.second;
		}
		return x.first < y.first;
	}
	return x.second - x.first + 1 < y.second - y.first + 1;
} 
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			int s = sum[i - 1] ^ sum[j];
			if (s == k){
				v.push_back(make_pair(i,j));
			}
		}
	}
	int cnt = 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++){
		cout << v[i].first << " " << v[i].second <<endl;
		bool flag = 1;
		for (int j = v[i].first; j <= v[i].second; j++){
			if (f[j]){
				flag = 0;
				break;
			}
		}
		if (flag){
			for (int j = v[i].first; j <= v[i].second; j++){
			f[j] = 1;
		}
		cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
} 

