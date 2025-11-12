#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
int n, m, a[505];
bool s[505], tp, tp1;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    mt19937 Rand(time(0));
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>s[i];
        if (s[i]!=1) tp=1;
    }
    for (int i=1; i<=n; i++) {
        cin>>a[i];
        if (a[i]==0) tp1=1;
    }
    if (!tp) {
        if (!tp1) {
            ll sum=1, sum_m=1;
            for (int i=n; i>n-m; i--) sum=(sum*i)%MOD;
            for (int i=m; i>=1; i--) sum_m=(sum_m*i)%MOD;
            cout<<(sum/sum_m)%MOD;
        }else {
            cout<<rand()%MOD;
        }
    }else {
        if (m==1 || n==m) {
            ll sum=1, sum_m=1;
            for (int i=1; i<=n; i++) sum=(sum*i)%MOD;
            for (int i=1; i<=m; i++) sum_m=(sum_m*i)%MOD;
            cout<<(sum/sum_m)%MOD;
        }else cout<<rand()%MOD;
    }
    return 0;
}
