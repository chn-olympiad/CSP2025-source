#include <bits/stdc++.h>
using namespace std;
int a[500005], sum[500005];
int l[500005], r[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	int m = 1;
	int maxn = -1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			if(sum[j] == k){
				l[m] = i;
				r[m++] = j-1;
				for(int x = 1; x < m; x++){
					for(int y = 1; y < x; y++){
						if(l[x] == l[y] || r[x] == r[y]){
							l[m-1] = 0;
							r[m-1] = 0;
						}
					}
				}
				maxn = max(maxn, l[m-1]-r[m-1]);
			}
		}
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
