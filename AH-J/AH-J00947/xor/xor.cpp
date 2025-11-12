#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n, k, kk, a[500005], two[500005][100], ans, l;

LL xor (LL a, LL b) {
    LL aa=a, an=1, bb=b, bn=1, ret=0;
    while (aa<10) {
        aa/=10, an++;
    }
    while (bb<10) {
        bb/=10, bn++;
    }
    for (int i=1; i<=max(an,bn); i++) {
        int p=(pow(i, 10);
        if (a/p!=b/p) ret+=p;
    }
    return ret;
}
bool dp (LL fl, LL t, LL cot) {
    if (t==kk) return 1;
    if (cot==fl) return 0;
    LL us;
    for (int i=l; i<=fl+1-cot; i++) {
        two[cot+1][i]=xor(two[cot][i], two[cot][i+1]);
        return dp(fl, two[cot+1][i], cot+1);
    }
}
int main () {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    {
        LL cmp=1, s=k;
        while (s>0) {
            kk+=(s%2)*cmp;
            s/=2;
            cmp*=10;
        }
        for (LL i=1; i<=n; i++) {
            cin >> a[i];
            cmp=1;
            s=a[i];
            while (s>0) {
                two[i][1]+=(s%2)*cmp;
                s/=2;
                cmp*=10;
            }
        }
    }

    /*for (int i=1; i<=n; i++) {
        for (int j=1; j<=c[i]; j++) cout << two[i][j];
    }*/
    for (int i=1; i<=n; i++) {
        if (dp(i, two[i][1], 1)) {
            ans++;
            l=i;
        }
    }
    cout << ans;
    return 0;
}
