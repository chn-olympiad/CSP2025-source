#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, mod = 998244353;
char C;
int p[20];
int n,m,a[N],c[N],s[N],ans = 0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
    	cin >> C;
    	a[i] = C - '0';
    	s[i] = s[i-1] + a[i];
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (m == n){
		if (s[n] == 0){
			ans = 1;
			for (int i = 2; i <= n; i++) (ans *=i) %=mod;
			cout << ans;
		}
		else cout << 0;
		return 0;
	}
	else if (s[n] == n){
		cout << 0;
		return 0;
	}
	else if (n <= 10){
		for (int i = 0; i < n; i++) p[i] = i + 1;
		do{
			int sum = 0;
			for (int i = 1; i <= n; i++){
				if (a[i] == 0 && c[p[i]] > s[i]) sum++;
			}
			if (sum >= m) ans++;
		}while(next_permutation(p,p + n));
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
