#include <iostream>
using namespace std;
typedef long long ll;
const ll P = 998244353 , mod = 1e9 + 7;
const int N = 2e5 + 5 , M = 2e5 + 5 , L = 5e6 + 5;
string s1[N] , s2[N] , t1 , t2;
int a[N] , n , m;
ll hs1[N] , hs2[N] , p[L] , h1[L] , h2[L];
ll Hash1(int l , int r){
    return ((h1[r] - h1[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}
ll Hash2(int l , int r){
    return ((h2[r] - h2[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}
int main(){
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1;i <= 5e6;i++) p[i] = p[i - 1] * P % mod;
    for (int i = 1;i <= n;i++){
        cin >> s1[i] >> s2[i];
        for (int j = 0;j < s1[i].size();j++) hs1[i] = (hs1[i] * P + s1[i][j] - 'a' + 1) % mod;
        for (int j = 0;j < s2[i].size();j++) hs2[i] = (hs2[i] * P + s2[i][j] - 'a' + 1) % mod;
        for (int j = 0;j < s1[i].size();j++){
            if (s1[i][j] != s2[i][j]){
                a[i] = j;
                break;
            }
        }
    }
    int k , x , y;
    while (m--){
        cin >> t1 >> t2;
        k = t1.size();
        t1 = ' ' + t1 , t2 = ' ' + t2;
        for (int i = 1;i <= k;i++) h1[i] = (h1[i - 1] * P + t1[i] - 'a' + 1) % mod; 
        for (int i = 1;i <= k;i++) h2[i] = (h2[i - 1] * P + t2[i] - 'a' + 1) % mod;
        for (int i = k;i >= 1;i--){
            if (t1[i] != t2[i]) x = i;
        }
        for (int i = 1;i <= k;i++){
            if (t1[i] != t2[i]) y = i;
        }
        int ans = 0 , l , r;
        for (int i = 1;i <= n;i++){
            l = x - a[i] , r = x - a[i] + s1[i].size() - 1;
            if (l >= 1 && r <= k && y <= r && Hash1(l , r) == hs1[i] && Hash2(l , r) == hs2[i]) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}