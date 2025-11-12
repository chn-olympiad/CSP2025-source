#include <bits/stdc++.h>
using namespace std;
int n, a[5005], b[5005], f[5005][25], ans, tp;
const int MOD=998244353;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>f[i][0];
        b[i]=f[i][0]+b[i-1];
        if (f[i][0]>1) tp=1;
    }
    if (tp==0) {
        //forget how to tepan
        tp=1;
    }
    for (int j=1; j<=22; j++) {
        for (int i=1; i<=n-(1<<j)+1; i++) {
            f[i][j]=max(f[i][j-1], f[i+(1<<j)-1][j-1]);
        }
    }
    //cout<<f[1][2];
    for (int i=3; i<=n; i++) {
        for (int j=1; j<=i-2; j++) {
            int k=log2(i-j+1);
            if (b[i]-b[j] > 2*f[i][k]) {
                ans=(ans+1)%MOD;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<ans%MOD;
    return 0;
}
// RMQ&(qian zhui he) ?  I forget RMQ/ll
// oh.I was wrong./bangbangt
// O(n^2)
// 2025csp-s rp++
