#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n, m;
string s;
int c[505];
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> s;
    int N = n;
    for(int i = 0;i < n;i++){
        cin >> c[i];
        if(c[i] == 0)   N--;
    }
    ll ans = 1;
    int cnt = 0;
    while(cnt <= m){
        ans *= N, ans %= mod;
        N--, cnt++;
    }
    cout <<ans << '\n';
    return 0;
}
