//手握日月摘星辰，世间无我这般人

#include<bits/stdc++.h>
using namespace std;

int n,a[1000000],f[1000000],ans[100000],k;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = (a[i] ^ f[i - 1]);
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			if((f[i] ^ f[j]) == k) {
				ans[i] = max(ans[j] + 1,ans[i]);
			}
		}
	}
	int maxn = -1;
	for(int i = 1; i <= n; i++) {
		maxn = max(ans[i],maxn);
	}

	cout << maxn;
	return 0;
}
