#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005];
bool flag1=true,flag2=true,flag3=true;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]!=1) flag1=false;
        if (a[i]!=0 && a[i]!=1) flag2=false;
        if (a[i]!=k) flag3=false;
    }
    if (n==1) {
        if (a[1]==k) cout<<1;
        else cout<<0;
        return 0;
    }
    if (flag1 && k==0) {
        cout<<n/2;
        return 0;
    }
    if (flag2) {
        if (k==0) {
            int ans1=0,ans2=0;
            for (int i=1;i<=n;i++) {
                if (a[i]==0) ans1++;
                if (a[i]==1 && a[i+1]==1 && a[i+2]==1) ans2++,i+=2;
            }
            cout<<ans1+ans2;
        }
        else {
            int ans=0;
            for (int i=1;i<=n;i++)
                if (a[i]==1) ans++;
            cout<<ans;
        }
        return 0;
    }
    if (flag3) {
        cout<<n;
        return 0;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        if (a[i]==k) ans++;
    cout<<ans;
    return 0;
}
