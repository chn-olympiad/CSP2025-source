#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 2e5 + 5;
const int M = 2e6 + 5;
const int B = 51971;
int n, Q, siz[N];
ull H[M], pw[M], a[N], b[N];

ull gethsh(string s){
    ull res = 0;
    for(char c : s){
        res = res * B + c;
    }
    return res;
}
ull quehsh(int l, int r){
    if(l > r) return 0;
    return H[r] - H[l - 1] * pw[r - l + 1];
}

int main(){

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> n >> Q;
    pw[0] = 1;
    for(int i = 1; i <= 2000; i++) pw[i] = pw[i - 1] * B;
    for(int i = 1; i <= n; i++){
        string s, t;
        cin >> s >> t;
        siz[i] = s.size();
        a[i] = gethsh(s), b[i] = gethsh(t);
    }
    string s, t;
    while(Q--){
        cin >> s >> t;
        if(s.size() != t.size()){
            cout << 0 << '\n';
            continue;
        }
        int len = s.size();
        for(int i = 1; i <= len; i++)
            H[i] = H[i - 1] * B + s[i - 1];
        ull tmp = gethsh(t);
        //cout << tmp << ' ' << H[len] << '\n';
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= len - siz[i] + 1; j++){
                ull t = quehsh(j, j + siz[i] - 1);
                if(a[i] == t){
                    //cout << i << ' ' << j << ' ' << t << '\n';
                    ull t2 = H[j - 1] * pw[len - j + 1] + b[i] * pw[len - j - siz[i] + 1] + quehsh(j + siz[i], len);
                    if(t2 == tmp){
                        //cout << i << ' ' << t2 << '\n';
                        ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

