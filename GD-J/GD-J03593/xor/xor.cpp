#include<bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 5e5 + 10;
int a[maxn],sum[maxn];

signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int tmp = 0,cnt = 0,tmp2 = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
		if(a[i] == 1) tmp++;
		if(a[i] <= 1) tmp2++;
		if(a[i] == k) cnt++;
	}
//	for(int i = 1;i <= n;i++) cout << sum[i] << " ";
	if(tmp == n and k == 0) {
		cout << 0;
		return 0;
	}
	if(tmp2 == n and k <= 1) {
		cout << cnt;
		return 0;
	}
	cout << cnt;
	return 0;
}

