#include<bits/stdc++.h>
using namespace std;

int n, k, a[500010][20], ans = 0;
int two[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		int x = 0;
		cin >> x;
		a[i][0] = x;
	}
	for(int i = 1;i <= log2(n);i++){
		for(int j = 1;j <= n;j++){
			a[j][i] = a[j][i - 1] xor a[j + two[i - 1]][i - 1];
		}
	}
	for(int i = n;i >= 1;i--){
		for(int j = i;j <= n;j++){
			int flag = 0;
			int i1 = i;
			while(i1 != j + 1){
				int b = log2(j - i1 + 1);
				flag = flag xor a[i1][b];
				i1 += two[b];
				//cout << b;
			}
			if(flag == k){
				ans++;
				n = i - 1;
				//cout << i << j;
			}
		}
	}
	cout << ans;
	return 0;
}
