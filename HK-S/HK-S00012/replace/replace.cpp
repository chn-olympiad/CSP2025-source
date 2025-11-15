#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
string a, b;
map<string, string>mp;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        mp[a] = b;
    }
    while (q--) {
        cin >> a >> b; int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            string t1 = "", t2 = "";
            for (int j = 0; j < i; j++) t1 += a[j], t2 += b[j];
            if (t1 != t2) continue;
            for (int j = i;j < a.size(); j++) {
                t1 = "", t2 = "";
                for (int k = j + 1; k < a.size(); k++) t1 += a[k], t2 += b[k];
                if (t1 != t2) continue;
                t1 = "", t2 = "";
                for (int k = i; k <= j; k++) t1 += a[k], t2 += b[k];
                if (mp[t1] == t2) ans++;
            }
        }
        cout << ans << "\n";
    }
    fclose(stdin); fclose(stdout);
}
