#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const long long inf = 0x3f3f3f3f3f3f3f3fLL, mod = 998244353;
int n, q, m;
string s[200005][3], A, B;
ull base = 131, bs[5000005], inst[200005][3], hsha[5000005], hshb[5000005];
inline void init(){
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < (int)s[i][1].size();j++){
            inst[i][1] = inst[i][1] * base + s[i][1][j];
        }
        for(int j = 0;j < (int)s[i][2].size();j++){
            inst[i][2] = inst[i][2] * base + s[i][2][j];
        }
    }
    bs[0] = 1;
    for(int i = 1;i <= 5000000;i++){
        bs[i] = bs[i - 1] * base;
    }
}
inline void init_q(){
    for(int i = 1;i <= m;i++){
        hsha[i] = hsha[i - 1] * base + A[i - 1];
    }
    for(int i = 1;i <= m;i++){
        hshb[i] = hshb[i - 1] * base + B[i - 1];
    }
}
inline ull geta(int l, int r){
    return hsha[r] - hsha[l - 1] * bs[r - l + 1];
}
inline ull getb(int l, int r){
    return hshb[r] - hshb[l - 1] * bs[r - l + 1];
}
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s[i][1] >> s[i][2];
    }
    init();
    while(q--){
        cin >> A >> B;
        m = A.length();
        init_q();
        int fi = m + 1, en = 0, ans = 0;
        for(int i = 1;i <= m;i++){
            if(A[i - 1] != B[i - 1]){
                fi = i;
                break;
            }
        }
        for(int i = m;i >= 1;i--){
            if(A[i - 1] != B[i - 1]){
                en = i;
                break;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int l = max(1, en + 1 - (int)s[i][1].length());l <= min(fi, m - (int)s[i][1].length() + 1);l++){
                int r = l + s[i][1].length() - 1;
                if(geta(l, r) == inst[i][1] && getb(l, r) == inst[i][2]){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
