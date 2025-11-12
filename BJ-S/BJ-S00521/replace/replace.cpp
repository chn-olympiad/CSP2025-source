#include <bits/stdc++.h>
using namespace std;
string s[200005][2];
map<string,string> mp;
int b[200005];
int f[200005],bac[200005];
int kmp[200005];
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q; cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> s[i][0] >> s[i][1];
        int cnt1 = 0,cnt2 = 0;
        for(int j = 0;j < s[i][0].size();j++) {
            if(s[i][0][j] == 'b') { cnt1 = j; f[i] = j; bac[i] = s[i][0].size() - j;}
            if(s[i][1][j] == 'b') { cnt2 = j; }
        }
        b[i] = cnt2 - cnt1;
    }

    while(q--) {
        string t1,t2; cin >> t1 >> t2;
        int cnt1 = 0,cnt2 = 0; int ans = 0;
        for(int j = 0;j < t1.size();j++) {
            if(t1[j] == 'b') { cnt1 = j; }
            if(t2[j] == 'b') { cnt2 = j; }
        }
        for(int i = 1;i <= n;i++) {
            if(cnt1 >= f[i] && t1.size() - cnt1 >= bac[i]) {
                if(b[i] == cnt2 - cnt1) ans ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
