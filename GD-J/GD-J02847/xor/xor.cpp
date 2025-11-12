#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 * 5 + 10;
int a[maxn], pre[maxn], st[maxn];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0;
	cin >> n >> k;
	int len = n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = (pre[i-1] ^ a[i]);
	} 
	for(int i = 1; i <= n; i++){
		if(len < i) break;
		for(int j = 1; j + i - 1 <= n; j++){
			int l = j, r = i + j - 1;
			bool f = 1;
			int pos = 0;
			for(int z = l; z <= r; z++){
				if(st[z] == 1){
					f = 0, pos = z;
					break;
				}
			}
			if(!f){
				j = pos;
				continue;
			}
			int tmp = (pre[r] ^ pre[l-1]);
			if(tmp == k){
				ans++, len -= (r - l + 1);
				//cout << l << ' ' << r << '\n';
				for(int z = l; z <= r; z++) st[z] = 1;
			} 
		}
	}
	cout << ans;
    return 0;
}
