#include<bits/stdc++.h>
using namespace std;
long long n,a[5007],s[5007],ans,c[5007];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int len = 0,j = 0;
	while(c[1] != n){
		len ++;
		c[len] = len + j;
		if (c[len] == n + 1){
			for(int k = len;k >= 1;k --){
				if (c[k] < n){
					len = k;
					c[k] ++;
					j = c[k] - len;
					break;
				}
			}
		}
		long long sum = 0,maxn = 0;
		for(int i = 1;i <= len;i ++){
			sum += a[c[i]];
			maxn = max(maxn,a[c[i]]);
		}
		if (sum > maxn * 2){
			ans ++;
		}
	}
	cout << ans;
	return 0;
} 
