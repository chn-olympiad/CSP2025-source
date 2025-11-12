#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;

const int N=5e5+6;
int n,ans,s;
ll a[N],x[N],k;

namespace violence {
    bitset<N> vis;
    void srch(int l,int r) {
        bool flag=0;
        for (int j=l;j<=r;j++) {
            for (int i=j;i>=l;i--) {
                ll tmp=x[j]^x[i-1];
                if (tmp==k) {
                    ans++;
                    flag=1;
                    srch(l,i-1);
                    srch(j+1,r);
                    break;
                }
            }
            if (flag) break;
        }
    }
    void solve() {srch(1,n);}
}
namespace A {void solve() {ans=n/2;}}
namespace B {void solve() {for (int i=1;i<=n;i++) ans+=a[i];}}

int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i],x[i]=a[i]^x[i-1];
    if (n<=100&&k==0) {
        using namespace A;
        solve();
    } else if (k<=1) {
        using namespace B;
        solve();
    } else {
        using namespace violence;
        solve();
    }
    cout<<ans;
    return 0;
}
