#include<bits/stdc++.h>
using namespace std;
struct node{
	int l, r;
}b[1000006];
int a[1000006], cnt;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
	}
	int c = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			int sum1 = a[i];
			for (int k = i + 1; k <= j; k ++){
				sum1 ^= a[k];
			}
			if (sum1 == k) {
				b[++ c].l = i;
				b[c].r = j;
			}
		}
	}
	int mx = -1;
	for (int i = 1; i <= c; i ++){
		int k = 1;
		int xxx = b[i].r;
		for (int j = i + 1; j <= c; j ++){
			if (b[j].l > xxx){
				k ++;
				xxx = b[j].r;
			} 
			
		}
		mx = max(mx, k);
	}
	cout << mx;
	return 0;
}
