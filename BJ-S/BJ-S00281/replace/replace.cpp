#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 2e5+10;
int n, q;
pair<string,string> a[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    while (q--) {
        int ans = 0;
        string t1,t2;
        cin >> t1>>t2;
        for (int i = 1; i <= n; i++) {
            //cout << i << endl;
            int it = t1.find(a[i].fi);
            while (it!=-1) {
                string t = t1;
                for (int j = it; j < it+a[i].fi.size(); j++) {
                    t[j] = a[i].se[j-it];
                }
                //cout << t << ' ' << t2 << endl;
                if (t==t2) {
                    ans++;
                }
                it = t1.find(a[i].fi, it+1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
