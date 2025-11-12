#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N], xo[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, ans=0;
	long long k;
	cin >> n >> k;
	unordered_map<long long, bool> cnt;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		xo[i] = xo[i-1]^a[i];
		cout << xo[i];
		if(xo[i]==k){
			xo[i]=0;
			ans++;
		} else if(cnt[xo[i]^k]){
			xo[i]=0;
			cnt[xo[i]^k] = false;
			ans++;
		} else {
			cnt[xo[i]] = true;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
