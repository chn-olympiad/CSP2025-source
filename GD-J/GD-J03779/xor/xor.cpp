#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], num = 0, f[5005][5005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) f[i][j] = -1;
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			int xo = a[i];
			for (int l = i;l <= j;l++){
				if(!(l == i)) xo ^= a[l];
			}
			f[i][j] = xo;
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			if(f[i][j] == k){
				num++;
				for (int l = 1;l <= i;l++)
					for (int r = 1;r <= n;r++) f[l][r] = -1;
				for (int l = i + 1;l <= n;l++)
					for (int r = 1;r <= j;r++) f[l][r] = -1;
			}
		}
	}
	cout << num;
	return 0;
}

