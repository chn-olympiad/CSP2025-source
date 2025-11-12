#include<bits/stdc++.h>
#define long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;

const int N = 5e5 + 10;

int n, k;
int a[N], c[N];
int ans, maxn;
bool fl[N];

signed main(){
	fin("xor.in");
	fout("xor.out");
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		c[i] = a[i] ^ c[i - 1];
		maxn = max(maxn, a[i]);
	}
	if(k > maxn){
		cout << 0;
		return 0;
	}
	for(int i = n; i >= 1; i--){
		if(fl[i]) continue;
		for(int j = i; j <= n; j++){
			if(fl[j]) break;
			int x = c[j] ^ c[i - 1];
			if(x == k){
				ans++;
//				cout << i << ' ' << j << '\n';
				fl[i] = fl[j] = 1;
				break;
			}
		}
		
	}
	cout << ans;
	return 0;
}

