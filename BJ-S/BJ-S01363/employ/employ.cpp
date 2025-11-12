#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 510;

const ll mod = 998244353;

ll a[N], p[N];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n > 10){
        ll ans = 1;
        for(int i = n; i >= 1; i--) ans = (ans * i) % mod;
        for(int i = 1; i <= m; i++){
			ll sum = 1;
			for(long long j = m; j >= m - i + 1; j--){
				sum = (sum * j) % mod;
			}
			if(i & 1) ans = (ans + sum) % mod;
			else ans = (ans - sum + mod) % mod;
		}
        cout << (ans + mod) % mod << endl; return 0;
    }
    ll ans = 0;
    do{
        int tmp = 0;
        for(int i = 1; i <= n; i++){
            if((i - 1) - tmp >= a[p[i]]) continue;
            if(s[i - 1] == '1') tmp++;
        }
        //for(int i = 1; i <= n; i++) cout << p[i] << " ";
        //cout << endl << tmp << endl;
        if(tmp >= m) ans++;
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
}
