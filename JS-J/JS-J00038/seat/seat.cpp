#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[105];
ll s[105][105];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> m >> n;
    ll k = n * m;
    for(ll i = 1; i <= k; i++){
        cin >> a[i];
    }
    ll r_s = a[1];
    ll p(1);
    sort(a + 1, a + k + 1, greater<int>());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[j][i] = a[p++];
        }
        i++;
        for(int j = m; j >= 1; j--){
            s[j][i] = a[p++];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i][j] == r_s){
                cout << j << ' ' << i;
                return 0;
            }
        }
    }
    return 0;
}


