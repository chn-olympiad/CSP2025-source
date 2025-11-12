#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll n, m, a1, x;
vector<ll> a;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n * m; i++){
        cin >> x;
        if (i == 1) a1 = x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll x = 1, y = 1, i1 = 1;
    for (ll i = 1; i <= n * m; i++){
        if (a[i - 1] == a1){
            cout << y << ' ' << x;
            break;
        }
        x += i1;
        if (x == n + 1 || x == 0){
            y++;
            i1 = (-i1);
            x += i1;
        }
    }
    return 0;
}
