#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5e5 + 1;
int n, k, a[N], s[N], ans, t, maxr;
struct node{
	int l, r;
}f[N];
bool cmp(node x, node y){
	return x.r < y.r;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			int sum = s[r] ^ s[l-1];
			if(sum == k){
				t++;
				f[t].l = l;
				f[t].r = r;
			}
		}
	}
	sort(f + 1, f + t + 1, cmp);
	for(int i = 1; i <= t; i++){
		if(maxr < f[i].l){
			maxr = f[i].r;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
