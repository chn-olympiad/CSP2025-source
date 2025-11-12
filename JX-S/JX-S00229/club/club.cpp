#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],c[N];
int ans;
int n;
void dfs(int i,int cnt,int cnta,int cntb,int cntc) {
    if (i == n + 1) {
        ans = max(ans,cnt);
        return;
    }
    if (cnta < n / 2) dfs(i + 1,cnt + a[i],cnta + 1,cntb,cntc);
    if (cntb < n / 2) dfs(i + 1,cnt + b[i],cnta,cntb + 1,cntc);
    if (cntc < n / 2) dfs(i + 1,cnt + c[i],cnta,cntb,cntc + 1);
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while (T--) {
        ans = 0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        cin >> n;
        bool flag = 1;
        for (int i=1;i<=n;++i) {
            cin >> a[i] >> b[i] >> c[i];
            if (b[i] || c[i]) flag = 0;
        }
        if (flag) {
            sort(a+1,a+1+n);
            int ans = 0;
            for (int i=n;i>=n/2;--i) ans += a[i];
            cout << ans << '\n';
            continue;
        }
        dfs(1,0,0,0,0);
        cout << ans << '\n';
    }
    return 0;
}
