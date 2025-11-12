#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
typedef unsigned long long ull;
const ull P = 131;
int n, q;
string s[MAXN][3];
ull h[MAXN][2];
ull f[MAXN];
ull p[MAXN];
int ans = 0;
void getans(const string& sa, const string& sb){
    for (int i = 1; i <= n; ++i){
        int pos = sa.find(s[i][1]);
        while (pos < sa.size()){
            //printf("i=%d,pos = %d\n", i, pos);
            string buf = sa;
            buf.replace(pos, s[i][1].size(), s[i][2]);
            if (buf == sb) ++ans;
            pos = sa.find(s[i][1], pos + s[i][1].size());
        }
    }
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> s[i][1] >> s[i][2];
    while (q--){
        string sa, sb;
        cin >> sa >> sb;
        ans = 0;
        getans(sa, sb);
        cout << ans << endl;
    }
    return 0;
}
