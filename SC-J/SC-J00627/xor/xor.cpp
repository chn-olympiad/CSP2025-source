#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int k, x = 0, r, n;
	cin >> n >> k;
	if (k == 0){
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] == k){
			x++;
			i--;
			n--;
		}
	}
	for(int l = 1;l <= n;l++){
		for (int r = l;r <= n;r++){
			int y = a[l];
			for (int i = l + 1;i <= r;i++){
				y = y ^ a[i];
			}
			if (y == k){
				x++;
				for (int i = l;i <= r;i++){
					a[i] = a[i + r - l + 1];
				}
				n -= r - l + 1;
			}
		}
	}
	cout << x;
	return 0;
}