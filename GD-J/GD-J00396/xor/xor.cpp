#include<bits/stdc++.h>
using namespace std;
long long mp[200005];
long long bck(long long x, long long y){
	bitset <25> a = x, b = y;
	long long c = 0;
	for(int i = 0; i <= 20; i++) if(a[i] != b[i]) c += (1 << i);
	return c;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, lr = 0, ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		long long x;
		cin >> x;
		mp[i] = bck(mp[i - 1], x);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j > lr; j--){
			if(bck(mp[i], mp[j - 1]) == k){
				ans++;
				lr = i;
				break;
			} 
		}
	}
	cout << ans;
	return 0;
}
