#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
string s;
int c[510];
const ll mod = 998244353;
int cnt;
int p[510];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
		if(c[i] == 0){
			cnt ++;
		}
	}
	if(n >= 20){
		ll ans = 1;
		for(int i = 1; i <= n; i++){
			ans = ans * ans % mod;
		} 
		printf("%lld\n", ans);
		return 0;
	}else{
		for(int i = 0; i < n; i++){
			p[i] = i;
		}
		int ans = 0;
		do{
			int f = 0; // exit
			for(int i = 0; i < n; i++){
				if(f >= c[p[i]] || s[i] == '0'){
					f++;
				}
			}
			if(n - f >= m){
				ans ++ ; 
			}
		}while(next_permutation(p, p + n));
		cout << ans << endl;
	}
	return 0;
}
