#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int n,a[N],b[N],c[N],ans,t,u;
int cnt[3];
bool f;

void dfs(int sum,int l) {
    if (sum > ans) ans = sum;
    //cout << sum << endl;
    for (int i = l + 1;i < n;i++) {
        int n1,n2,n3,m1,m2,m3;
        m1 = max(max(a[i],b[i]),c[i]);
        m3 = min(min(a[i],b[i]),c[i]);
        if (a[i] >= b[i] && a[i] >= c[i]) {
            n1 = 0;
            if (b[i] >= c[i]) {n2 = 1; m2 = b[i];}
            else {n2 = 2; m2 = c[i];}
            n3 = 3 - n2;
        } else if (b[i] >= a[i] && b[i] >= c[i]) {
            n1 = 1;
            if (a[i] >= c[i]) {n2 = 0; m2 = a[i];}
            else {n2 = 2; m2 = c[i];}
            n3 = 2 - n2;
        }
        else {
            n1 = 2;
            if (a[i] >= b[i]) {m2 = a[i]; n2 = 0;}
            else {n2 = 1; m2 = b[i];}
            n3 = 1 - n2;
        }
        if (cnt[n1] + 1 <= u) {
            ++cnt[n1];
            dfs(sum + m1,i);
            --cnt[n1];
        } if (cnt[n2] + 1 <= u) {
            ++cnt[n2];
            dfs(sum + m2,i);
            --cnt[n2];
        } if (cnt[n3] + 1 <= u) {
            ++cnt[n3];
            dfs(sum + m3,i);
            --cnt[n3];
        }
    }
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        f = false;
        memset(cnt,0,sizeof(cnt));
        ans = 0;
        cin >> n;
        u = n / 2;
        for (int i = 0;i < n;i++) {
            cin >> a[i] >> b[i] >> c[i];
            if (b[i] != 0) f = 1;
        }
        if(!f) {
            sort(a,a+n);
            int cnt = 0;
            for (int i = n - 1;cnt * 2 <= n;i--) {
            ans += a[i]; ++cnt;
            }
            cout << ans;
            continue;
        }
        dfs(0,-1);
        cout << ans;
    }
}
