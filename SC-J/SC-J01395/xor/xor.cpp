#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], dp[500005], sum;
bool f[500005];
bool check(int x){
	bool fl = 0;
	int j = a[x];
	if(j == k){
		f[x] = 1;	
		return 1;
	}
	for(int i = x - 1;i >= 1;i--){
		if(f[i])break;
		j = (j ^ a[i]);
		if(j == k){
			for(int j = i;j <= x;j++){
				f[j] = 1;
			}
			return 1;
		}
	}
	return fl;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d, %d", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
		if(check(i))dp[i]++;
	}
	cout << dp[n];
	return 0;
} 