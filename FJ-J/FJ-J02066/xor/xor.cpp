#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
long long sum[500005] = {};

int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	} 
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(sum[i] - sum [j - 1] == k){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
