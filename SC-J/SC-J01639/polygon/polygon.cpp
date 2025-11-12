#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3 + 7, mod = 998244353;
struct node{
	int ans = 0, u;
};
int n, a[N], s[N];
bool f = 1;
ll ans = 0;
ll c(int n, int m){
	if(n > m / 2) return c(m - n, m);
	ll ans = 1;
	for(int i = m - n + 1; i <= m; i++){
		ans *= i;
		ans %= mod;
	}
	for(int i = 1; i <= n; i++){
		ans /= i;
		ans %= mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		if(a[i] > 1) f = 0;
	}
	if(f){
		for(int i = 3; i <= n; i++){
			ans += c(i, n);
			ans %= mod;
		}
	}else{
		sort(a + 1, a + n + 1);
		for(int i = 3; i <= n; i++){
			queue<node> q;
			q.push({0, 1});
			while(!q.empty()){
				node t = q.front();
				q.pop();
				if(t.u >= i){
					if(t.ans > a[i]) ans++;
					ans %= mod;
					continue;
				}
				q.push({t.ans + a[t.u], t.u + 1});
				q.push({t.ans, t.u + 1});
			}
		}	
	}
	printf("%lld", ans % mod);
	return 0;
}