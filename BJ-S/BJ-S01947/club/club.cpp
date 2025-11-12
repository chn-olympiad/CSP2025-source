#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n, mx[N], cg[N], cnt[3], ans, as[N];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cnt[0] = cnt[1] = cnt[2] = ans = 0;
        cin >> n;
        for(int i = n; i; --i) {
            int a[3] = {0, 0, 0}, as1 = 2, as2 = 2;
            for(int j = 2; ~j; --j) {
                cin >> a[j];
                if(a[j] > a[as1]) as2 = as1, as1 = j;
                else if(a[j] > a[as2] || as1 == as2) as2 = j;
            }
            ++cnt[as1], mx[i] = as1, cg[i] = a[as2] - a[as1], ans += a[as1];
            //cout << as1 << "  " << cg[i] << "  " << ans << endl;
        }
       //cout << cnt[0] << "  " << cnt[1] << "  " << cnt[2] << endl;
        int op = max(cnt[0], max(cnt[1], cnt[2]));
        if(op == cnt[0]) op = 0;
        else if(op == cnt[1]) op = 1;
        else op = 2;
        if(cnt[op] > (n >> 1)) {
            for(int i = n; i; --i) as[i] = mx[i] == op ? cg[i] : -0x7fffffff;
            sort(as + 1, as + n + 1);
            for(int i = n; i; --i) {
                //cout << i <<  "  " << as[i] << endl;
                ans += as[i];
                if(--cnt[op] <= (n >> 1)) break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}