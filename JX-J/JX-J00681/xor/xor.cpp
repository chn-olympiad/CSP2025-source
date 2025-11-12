#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
intl n,k,a[N],xsum[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (intl i=1;i<=n;i++) {
        cin>>a[i];
        xsum[i]=xsum[i-1]^a[i];
    }
    intl maxr=0,ans=0;
    for (intl r=1;r<=n;r++) {
        for (intl l=maxr+1;l<=r;l++) {
            if ((xsum[r]^xsum[l-1])==k) {
                ans++;
                maxr=r;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}