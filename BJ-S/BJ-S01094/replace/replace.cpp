#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pss pair<string, string>
using namespace std;
ll n, q;
map<string, ll> mp;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1 + s2]++;
        //cout << "mp[" << s1 + s2 << "]++" << endl;
    }
    while(q--) {
        string t1, t2;
        cin >> t1 >> t2;
        ll l = t1.size();
        t1 = " " + t1 + " ";
        t2 = " " + t2 + " ";
        ll ans = 0;
        int L = 0, R = n + 1;
        while(t1[L] == t2[L]) {
            L++;
        }
        while(t1[R] == t2[R]) {
            R--;
        }
        for(ll i = 1; i <= l; i++) {
            if(i > L) {
                break;
            }
            string a = "", b = "";
            for(ll j = i; j <= l; j++) {
                a.push_back(t1[j]);
                b.push_back(t2[j]);
                if(i <= L && R <= j) {
                    //cout << i << " -> " << j << ": " << a + b << endl;
                    ans += mp[a + b];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
