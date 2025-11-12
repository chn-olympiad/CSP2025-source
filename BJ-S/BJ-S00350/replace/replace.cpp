#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int n, q, l[N];
string s[N][2], t1, t2;
struct qwq{
    string s;
    int l, hs[N], Pow[N];
    static const int base = 31;
    static const int mod = 998244353;
    qwq(){}
    void init(string st){
        s = st;
        l = s.size();
        hs[0] = s[0] - 'a';
        Pow[0] = 1;
        for (int i = 1;i < l;i++){
            Pow[i] = Pow[i - 1] * base % mod;
            hs[i] = (hs[i - 1] * base % mod + (s[i] - 'a')) % mod;
        }
    }
    int h(int l, int r){
        return (hs[r] - hs[l - 1] * Pow[r - l + 1] % mod + mod) % mod;
    }
}s1[N][2];
bool cmp(qwq a, int l1, int r1, qwq b, int l2, int r2){
    return a.h(l1, r1) == b.h(l2, r2);
}
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1;i <= n;i++){
        cin >> s[i][0] >> s[i][1];
        l[i] = s[i][0].size();
        s1[i][0].init(s[i][0]);
        s1[i][1].init(s[i][1]);
    }
    while (q--){
        cin >> t1 >> t2;
        int l1 = t1.size(), l2 = t2.size();
        if (l1 != l2){
            cout << "0\n";
            continue;
        }
        qwq T1, T2;
        T1.init(t1); T2.init(t2);
        int cnt = 0;
        for (int i = 1;i <= n;i++){
            for (int j = 0;j + l[i] - 1 < l1;j++){
                /*
                if (t1.substr(0, j) == t2.substr(0, j) && t1.substr(j, l[i]) == s[i][0] && t2.substr(j, l[i]) == s[i][1] && t1.substr(j + l[i], l1 - (j + l[i])) == t2.substr(j + l[i], l1 - (j + l[i]))){
                    cnt++;
                    cout << i << ' ' << j << endl;
                }
                */
                if (cmp(T1, 0, j - 1, T2, 0, j - 1) && cmp(T1, j, j + l[i] - 1, s1[i][0], 0, l[i] - 1) && cmp(T2, j, j + l[i] - 1, s1[i][1], 0, l[i] - 1) && cmp(T1, j + l[i], l1 - 1, T2, j + l[i], l1 - 1)){
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}
