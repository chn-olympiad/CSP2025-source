#include<bits/stdc++.h>
using namespace std;
int n, l[5005], sum, f[6005], ans;
const int mod = 998244353;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &l[i]), sum += l[i];
    sort(l + 1, l + n + 1); f[0] = 1;
    for(int i = 1; i < n; i++){
    	ans = (ans + f[l[i] + 1]) % mod;
    	for(int j = l[n] + 10; j >= 0; j--) f[j] = (f[j] + f[max(0, j - l[i])]) % mod;
	} 
    ans = (ans + f[l[n] + 1]) % mod;
    printf("%d", ans);
	return 0;
}

