#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 5005;
int n,way;
int a[N];
int b[N];
void dfs(int x, int sum, int maxn){
	if(x == n + 1){
		if(sum > maxn * 2){
			way++;
			way %= mod;
		}
		return;
	}
	if(sum > a[n] * 2){
		way = way + (1 << (n - x + 1));
		way %= mod;
		return;
	}//*/
	dfs(x + 1, sum, maxn);
	dfs(x + 1, sum + a[x], max(maxn, a[x]));
}
void f(){
	int sum0, sum1, sumt, sumt1;
	sum0 = sum1 = sumt = 0;
	sumt1 = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			sum0++;
		} else{
			sum1++;
		}
	}
	for(int i = 1; i <= sum0; i++){
		sumt1 = sumt1 * 2;
		sumt1 = (sumt1 - 1) % mod + 1;
	}
	for(int i = sum1; i >= 1; i--){
		sumt = sumt + (1 << (i - 1)) - (i - 1);
		sumt %= mod;
	}
	int tt = sumt1 * sumt;
	tt = tt % mod;
	printf("%lld",tt);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1, a + 1 + n);
	if(a[n] == 1){
		f();
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",way);
	return 0;
}
/*
5
2 2 3 8 10
*/
