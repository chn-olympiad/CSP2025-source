#include<bits/stdc++.h>
#define int long long
const int mod = 998244353,N = 6000;
using namespace std;
int n;
int a[N];
int ans = 0;
int maxi = -1;
bool flag = 1;
void dfs(int sum,int idx,int tot,int maxn){
	if(tot == 0){
		if(sum > maxn * 2){
			ans = (ans + 1) % mod;
		}
		return;
	}
	for(int i = idx + 1; i <= n; i++){
		dfs((sum + a[i]) % mod,i,tot - 1,max(maxn,a[i]) % mod);
	} 
}
int C(int n,int m){
	int a = 1,b = 1;
	for(int i = 1; i <= m; i++){
		a = (a * i) % mod;
	}
	for(int i = n; i >= n - m + 1; i--){
		b = (b * i) % mod;
	}
	return (b / a) % mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		if(i != 1 and a[i - 1] != a[i]) flag = 0;
		maxi = max(a[i],maxi);
	}
	if(maxi == 1 or flag == 1){
		for(int i = 3; i <= n; i++){
			ans = (ans + C(n,i)) % mod;
		}
		printf("%d",ans % mod);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 3; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dfs(a[j],j,i - 1,-1);
		}
	}
	printf("%d",ans % mod);
	return 0;
}
