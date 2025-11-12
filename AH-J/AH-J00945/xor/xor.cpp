#include <bits/stdc++.h>
using namespace std; 
const int N = 5e5 + 5; 
int n, k, ans, a[N], sum[N]; 
vector <pair <int, int> > v; 
int main() {
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr); 
    freopen("xor.in", "r", stdin); 
    freopen("xor.out", "w", stdout); 
    cin >> n >> k; 
    for (int i = 1; i <= n; i++)
		cin >> a[i]; 
	for (int i = 1; i <= n; i++)
		sum[i] = (sum[i - 1] ^ a[i]); 
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			if ((sum[j] ^ sum[i - 1]) == k)
				v.push_back(make_pair(i, j)); 
		}
	}
	int last = 0; 
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first > last)
			ans++, last = v[i].second; 
		else if (v[i].second < last)
			last = v[i].second; 
	}
	cout << ans << endl; 
    return 0; 
}
