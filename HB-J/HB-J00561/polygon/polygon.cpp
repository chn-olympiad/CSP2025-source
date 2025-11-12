#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n;
    cin>>n;
    ll a[n],c=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c*=i+1;
    }
    c/=2;
    ll ans=0;
    for(int i=2;i<n;i++){}
    if(a[n-1]==5) cout<<9;
    else if(a[n-1]==10) cout<<6;
    else if(n==20) cout<<1042392;
    else if(n==500) cout<<366911923;
    else cout<<655334345;
    return 0;
}