#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n;
    cin>>n;
    ll a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll sum=a[1]+a[2]+a[3];
    ll t=a[3]*2;
    if(sum>t)cout<<1;
    else cout<<0;

    return 0;
}
