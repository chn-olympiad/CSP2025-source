#include<bits/stdc++.h>
using namespace std;
//xhz

long long T;

int main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while (T--) {
        long long ans=0;
        long long a,b,c,n;
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a>>b>>c;
            ans+=max(a,max(b,c));
        }
        cout<<ans<<endl;
    }
    return 0;
}
