#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll a[n*m];
    for(ll i=0;i<n*m;i++) cin>>a[i];
    ll A=a[0];
    sort(a,a+m*n);
    ll c,r,cnt;
    for(int i=0;i<n*m;i++){
        if(a[i]==A){
            cnt=n*m-i;
        }
    }
    c=(cnt-1)/m+1;
    r=(cnt-1)%n+1;
    if(c%2==0) r=n-r+1;
    cout<<c<<' '<<r;
    return 0;
}