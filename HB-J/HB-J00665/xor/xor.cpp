#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll N,k,maxn = 0;
	cin >> N >> k;
	ll a[500005];
	
	for(int i = 1;i <= N;i ++) {
		cin >> a[i];
		maxn = max(maxn,a[i]);
	}
	cout << maxn;
	return 0;
	// i forget about xor-mathing.
}
