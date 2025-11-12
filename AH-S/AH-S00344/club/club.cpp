#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N][3],n;
int maxn[N];
int midn[N];
struct node{
    int more, less;
    int delta;
    bool operator<(node b){return delta > b.delta;}
} s[N];
int top = 0;
void solve(int m, int mn){
    ll ans = 0;
    top = 0;
    for (int i = 0; i < n; i++){
        if (maxn[i] != m) ans += a[i][maxn[i]];
        else {
            node c{a[i][maxn[i]], a[i][midn[i]]};
            c.delta = c.more - c.less;
            s[top++] = c;
        }
    }
    sort(s, s+top);
    int i = 0;
    for (; i < n/2; i++) ans += s[i].more;
    for (; i < top; i++) ans += s[i].less;
    cout << ans << '\n';

}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        int m0 = 0, m1 = 0, m2 = 0; 
        for (int i = 0; i < n;i ++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if (a[i][0] > a[i][1]){
                if (a[i][2] > a[i][0]) m2++, maxn[i] = 2, midn[i] = 0;
                else if (a[i][2] > a[i][1]) m0++, maxn[i] = 0, midn[i] = 2;
                else m0++, maxn[i] = 0, midn[i] = 1;
            }else if (a[i][2] > a[i][1]) m2++, maxn[i] = 2, midn[i] = 1;
            else if (a[i][2] > a[i][0]) m1++, maxn[i] = 1, midn[i] = 2;
            else m1++, maxn[i] = 1, midn[i] = 0;
        }
        int m;
        if (m0 > m1){
            if (m2 > m0) m = 2;
            else m = 0;
        } else if (m2 > m1) m = 2;
        else m = 1;
        int mn = max(max(m0, m1), m2);
        if (mn <= n/2){
            ll ans = 0;
            for (int i = 0; i < n; i ++)
                ans+=a[i][maxn[i]];
            cout << ans << '\n';
        } else {
            solve(m, mn);
        }
    }
    return 0;
}