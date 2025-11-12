#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e2 + 10, mod = 998244353;

vector<int> v(N), q(N);

inline int read(){
	int x=0;char s=getchar();
	while(!isdigit(s)) s=getchar();
	while(isdigit(s)) x=(x<<1)+(x<<3)-'0'+s,s=getchar();
	return x;
}

inline bool bd(){
	char s=getchar();
	while(!isdigit(s)) s=getchar();
	return s-'0';
}

void solve(){
	int n = read(), m = read();
	if(n == m){
		int t = 1;
		for(int i=1;i<=n;i++){
			int x = bd();
			if(x == 0){
				t = 0;
				break;
			}
		}
		if(t){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
		return;
	}
	for(int i=1;i<=n;i++){
		v[i] = v[i - 1] * 2 + 1;
		v[i] %= mod;
	}
	q[1] = n;
	int ssum = n - 1;
	for(int i=2;i<=m - 1;i++){
		q[i] = q[i - 1] * ssum;
		q[i] = q[i] / i;
		q[i] %= mod;
		ssum--;
	}
	for(int i=1;i<=m - 1;i++){
		q[i] += q[i - 1];
	}
	cout << v[n] << ' ' << q[m - 1] << '\n';
	printf("%lld", (v[n] - q[m - 1] + mod) % mod);
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = 1;

	while(T--){
		solve();
	}
	return 0;
}

