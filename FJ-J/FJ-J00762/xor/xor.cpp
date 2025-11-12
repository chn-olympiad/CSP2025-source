#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int maxn = 5 * 1e5 + 5;
long long a[maxn];
long long r = 0;
long long sum = 0;
vector<pair<int,int> >v;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int f = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0) f++;
	}
	if(k == 0) {
		cout << f << endl;
		exit(0);
	}
	for(int l = 1; l <= n; l++) {
		for(int h = 1; h <= n - l + 1; h++) {
			int ans = 0;
			for(int i = l; i <= h; i++) {
				ans ^= a[i];
			}
			if(ans == k) v.push_back(make_pair(l,h));
		}
	}
	for(int i = 1;i <= v.size();i++) {
		long long g = 1;
		for(int j = i + 1;j <= v.size();j++) {
			if(v[j].first > v[i].second || v[j].second < v[i].first) {
				g++;
			}
		}
		if(g != 1) sum = max(sum,g);
	}
	cout << sum << endl;
	return 0;
}
