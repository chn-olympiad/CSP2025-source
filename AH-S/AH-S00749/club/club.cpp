#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
int ans;
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1; i<=n; i++) {
            cin>>a[i]>>b[i]>>c[i];
            if (a[i]>=b[i]&&a[i]>=c[i]) ans+=a[i];
            if (b[i]>=a[i]&&b[i]>=c[i]) ans+=b[i];
            if (c[i]>=b[i]&&c[i]>=a[i]) ans+=c[i];
            cout <<ans<<endl;
        }
    }
    return 0;
}
