#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[10005]={};
void f(int q) {
    if (q==m) {
        ans++,ans%=998244353;
        return;
    }
    for (int i=1;i<=n;i++)
        if (!a[i]) {
            a[i]=1;
            f(q+1);
            a[i]=0;
        }
}
int main () {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    f(0);
    cout << ans;
    return 0;
}
