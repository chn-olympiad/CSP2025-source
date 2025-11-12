#include<bits/stdc++.h>
using namespace std;

int n,k,b[1005][1005],cnt,ans = 1;

struct dknow {
    int s,e;
}a[1005];

bool cmp(dknow x,dknow y) {
    return x.e < y.e;
}

int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> b[i][i];
        if (b[i][i] == k) {
            a[cnt].s = i;
            a[cnt].e = i;
            ++cnt;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            b[i][j] = b[i][j - 1] ^ b[j][j];
            if(b[i][j] == k) {
                a[cnt].s = i; a[cnt].e = j;
                cnt++;
            }
        }
    }
    sort(a,a+cnt,cmp);
    int l = 0;
    for (int i = 1;i < cnt;i++) {
        if (a[i].s > a[l].e) {
            ++ans;
            l = i;
        }
    }
    cout << ans;
    return 0;
}
