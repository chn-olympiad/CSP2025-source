#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vector<int> 
#define sz(a) ((int)a.size()) 
using namespace std;

const int N = 5e5 + 10;
int n, k;
int a[N], sum[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	L(i, 1, n) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	set<int> s;
	s.insert(0);
	int ans = 0;
	L(i, 1, n) {
		if(s.count(sum[i] ^ k) != 0) {
			ans++;
			s.clear();
		}
		s.insert(sum[i]);
	} 
	cout << ans << '\n';
	return 0;
} 
