#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
int n, k;
int a[N];
struct node {
    int l, r;
    bool friend operator < (node a, node b) {
        return a.r < b.r;
    }
}t[N * N];
int cnt;
bool f;
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] > 1)
            f = 1;
    }
    if(!f && n >= 1000) {
        int ans = 0;
        if(k == 0)
            for(int i = 1; i <= n; i++) {
                if(a[i] == 0)
                    ans++;
                if(a[i] == 1 && a[i + 1] == 1)
                    ans++, i++;
            }
        else
            for(int i = 1; i <= n; i++)
                if(a[i] == 1)
                    ans++;
        cout << ans;
        return 0;
    }
    for(int l = 1; l <= n; l++) {   
        int xor_sum = 0;
        for(int r = l; r <= n; r++) {
            xor_sum ^= a[r];
            if(xor_sum == k)
                t[++cnt] = {l, r};
        }
    }
    sort(t + 1, t + 1 + cnt);
    int ans = 0, rgt = 0;
    for(int i = 1; i <= cnt; i++) {
        if(t[i].l > rgt)
            rgt = t[i].r, ans++;
    }
    cout << ans << '\n';
}
/*
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
*/
