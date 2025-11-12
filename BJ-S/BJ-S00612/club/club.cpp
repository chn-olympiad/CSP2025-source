#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,t;
struct id{
    ll i1,i2,i3;
}a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        ll ans;
        for(int j=1;j<=n;j++)cin>>a[j].i1>>a[j].i2>>a[j].i3;
        ans=max(a[1].i1+a[2].i2,max(a[1].i1+a[2].i3,max(a[1].i2+a[2].i1,max(a[1].i2+a[2].i3,max(a[1].i3+a[2].i1,a[1].i3+a[2].i2)))));
        cout<<ans<<endl;
    }

}