#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll maxn = 5000 + 55, mod = 998244353, inf = 2147483647;
const double pi = acos(-1);
ll n, m;
ll a[maxn], f[maxn], fra[maxn], inv[maxn], inv2;
ll ans, res;
bool w;
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1; 
	}return res;
}
void init(){
	fra[0] = 1;
	for(int i = 1;i <= n;i ++){
		fra[i] = fra[i - 1] * i % mod;
	}
	inv[n] = qpow(fra[n], mod - 2);
	for(int i = n - 1;i >= 0;i --){
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
	inv2 = qpow(2, mod - 2);
	return;
}
ll c(ll n, ll m){
	if(n < m) return 0ll;
	if(n == m) return 1ll;
	return fra[n] * inv[m] % mod * inv[n - m] % mod;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	init();
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] != 1) w = 1;
	}
	sort(a + 1, a + n + 1);
	
	if(n == 3){
		if(a[1] + a[2] >= a[3]){
			cout << 1;
		}else cout << 0;
		return 0;
	}
	
	if(w == 0){
		for(int i = 3;i <= n;i ++){
			ans += c(n, i);
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	
	for(int i = 1;i <= n;i ++){
		f[i] = f[i - 1] + a[i];
	}
	
	for(int i = 3;i <= n;i ++){
		if(f[i - 1] < a[i]) continue;
		res += c(n, i) % mod;
		res -= c(n - 1, i) % mod;
		res %= mod;
	}
	
//	for(int i = 3;i <= n;i ++){//以第i位值作为最大值 
//		if(f[i - 1] < a[i]) continue;
//		//可以等价于求一个组合，满足第1-i - 1位值之和大于i的方案数 
//		for(int k = 2;k < i;k ++){//选择第1——第i - 1中的k根木棒 
//		//如：当i = 3时，从选择前2根开始枚举 
//			ans = c(i, k);//初始大小，假设全部满足
//			cout << ans << endl;
//			//减去最小的满足条件的组合方案前的所有，则剩余的一定都大于第三位 
//			ans = (ans + mod) % mod;
//			res += ans;
//			res %= mod;
//		}
//	}
	
	
	cout << (res + mod) % mod;
	return 0;
}