#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int a[500005];

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	scanf ("%lld%lld", &n, &k);
	for (int i = 1;i <= n;i++){
		scanf ("%lld", &a[i]);
	}
	int t = 0, ans = 0;
	for (int i = 1;i <= n;i++){
		t = a[i] ^ t;
		if (t == k){
			t = 0;
			ans++;
		}
	}
	printf ("%lld\n", ans);
	return 0;
}
