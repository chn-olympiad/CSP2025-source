#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 5e5 + 5;
int n, k, ans, l = 1, a[maxn], s[maxn], f[maxn];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	} 
	for(int i = 1; i <= n; i++){
		int l;
		for(int j = i; j >= 1; j--){
			if((s[i] ^ s[j-1]) == k){
				f[i] = 1;
				l = j;
				break;
			}
		}
		if(!l) continue;
		for(int j = l-1; j >= 1; j--){
			f[i] = max(f[j] + 1, f[i]);
		}
	} 
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans;
	return 0;
}
