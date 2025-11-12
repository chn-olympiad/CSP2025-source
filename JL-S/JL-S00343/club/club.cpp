#include <bits/stdc++.h>
using namespace std;
int T,n,a[1005]={},b[1005],c[10005],dp[10005]={};
int main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T--) {
        int ans=0;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
        if (b[2]==b[3] && b[2]==0) {
            sort(a+1,a+n+1);
            for (int i=1;i<=n/2;i++) ans+=a[i];
            cout << ans << '\n';
        } else if (n==2) {
            cout << max(max(a[1]+b[2],max(a[1]+c[2],c[1]+b[2])),max(b[2]+c[1],max(b[2]+a[1],c[1]+a[2])));
        }

    }
    return 0;
}

