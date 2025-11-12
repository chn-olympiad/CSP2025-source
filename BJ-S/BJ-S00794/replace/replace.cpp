#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair <int, int> pll;
const ll MAXN = 1e7 + 5;
const ll maxn = 2e5 + 5;
const ll off = 5e6;
const LL base = 2;
const LL mod = 1e9 + 7;
ll n, q;
LL ans;
vector <pll> v[MAXN];
string s, t, a[maxn][2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    if(n <= 1000){
        for(ll i = 1; i <= n; ++i){
            cin >> s >> t;
            a[i][0] = s, a[i][1] = t;
        }
        for(; q; --q){
            ans = 0;
            cin >> s >> t;
            if(s.size() != t.size()){
                cout << "0\n";
                continue;
            }
            for(ll j = 1; j <= n; ++j)
                for(ll k = 0; k < s.size() - a[j][0].size() + 1; ++k){
                    if(s.substr(k, a[j][0].size()) == a[j][0]){
                        if(s.substr(0, k) == t.substr(0, k) && t.substr(k, a[j][0].size()) == a[j][1] && s.substr(k + a[j][0].size(), s.size() - (k + a[j][0].size()) + 1) == t.substr(k + a[j][0].size(), s.size() - (k + a[j][0].size()) + 1)) ans++;
                    }
                }
            cout << ans << '\n';
        }
        return 0;
    }
    for(ll i = 1; i <= n; ++i){
        cin >> s >> t;
        ll sb, tb;
        for(ll j = 0; j < s.size(); ++j)
            if(s[j] == 'b') sb = j;
        for(ll j = 0; j < t.size(); ++j)
            if(t[j] == 'b') tb = j;
        if(s.size() == t.size()) v[sb - tb + off].push_back({sb - 1, (ll)s.size() - sb - 1});
    }
    for(ll i = 0; i <= off + off; ++i) sort(v[i].begin(), v[i].end());
    for(ll i = 1; i <= q; ++i){
        ans = 0;
        cin >> s >> t;
        if(s.size() != t.size()){
            cout << "0\n";
            continue;
        }
        ll sb, tb;
        for(ll j = 0; j < s.size(); ++j)
            if(s[j] == 'b') sb = j;
        for(ll j = 0; j < t.size(); ++j)
            if(t[j] == 'b') tb = j;
        ll tmp = sb - tb + off;
        int k = upper_bound(v[tmp].begin(), v[tmp].end(), make_pair(sb, -1)) - v[tmp].begin();
        k--;
        if(k < 0){
            cout << "0\n";
            continue;
        }
        for(ll i = k; i >= 0; --i)
            if(v[tmp][i].second <= (ll)s.size() - sb - 1) ans++;
        cout << ans << '\n';
    }
    return 0;
}
/*
5 3
b b
ba ba
aab baa
abaa aaab
baaaa aaaba
aaaaab aaaaab
aaaaaba baaaaaa
aaaaabaa aaaabaaa
*/
