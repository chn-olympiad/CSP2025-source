#include <bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,m,c[505],o,ans=1;
bool s[505];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    o=n;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>c[i];
        if (c[i]==0) {
            o--;
        }
    }
    if (o<m) {
        cout<<0<<endl;
        return 0;
    }
    for (int i=o;i>=1;i--) {
        ans*=i;
        ans%=mod;
    }
    cout<<ans;

    return 0;
}
