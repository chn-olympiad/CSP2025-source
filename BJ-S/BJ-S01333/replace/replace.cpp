#include <bits/stdc++.h>
#define int long long
#define l first
#define r second
using namespace std;
int n,q;
pair <int,int> p1[200005],p2[200005];
int a[200005];
signed main () {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        string s1,s2;
        cin >> s1 >> s2;
        int x,y;
        int sz = s1.size();
        for (int j = 0;j < sz;j++) {
            if (s1[j] == 'b') {
                x = j;
            }
            if (s2[j] == 'b') {
                y = j;
            }
        }
        p1[i] = {x - 1,sz - x};
        p2[i] = {y - 1,sz - y};
        a[i] = x - y;
    }
    while (q--) {
        int ans = 0;
        string t1,t2;
        cin >> t1 >> t2;
        int sz = t1.size();
        int x,y;
        for (int j = 0;j < sz;j++) {
            if (t1[j] == 'b') {
                x = j;
            }
            if (t2[j] == 'b') {
                y = j;
            }
        }
        int A = x - y;
        for (int i = 1;i <= n;i++) {
            bool bl =  (a[i] == A);
            bl &= (x - p1[i].l > 0 && y - p2[i].l > 0);
            bl &= (x + p1[i].r <= sz && y + p2[i].r <= sz);
            ans += bl;
        }
        cout << ans << endl;
    }
    return 0;
}