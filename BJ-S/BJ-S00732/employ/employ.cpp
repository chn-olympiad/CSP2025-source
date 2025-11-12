#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 998244353;
ll n, m, ans, s;
vector<ll> c;

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (ll i = 1; i <= n; i++){
        ll tmp = 0;
        cin >> tmp;
        c.push_back(tmp);
    }
    bool f = 1;
    ll b = s;
    while(1){
		if(b%10==0){
			f = 0;
			break;
		}
		b/=10;
		if(b < 10){
			if(b==0){
				f = 0;
			}
			break;
		}
	}
    if (f){
        ans = 1;
        for (ll i = n; i > 0; i--){
            ans *= i;
            if (ans > MOD)
                ans %= MOD;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
