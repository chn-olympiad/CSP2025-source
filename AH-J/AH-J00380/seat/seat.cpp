#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[110],ans=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]) ans++;
    }
    ll x=ceil((ans*1.0)/(n*1.0));
    ans-=(x-1)*n;
    ll y=0;
    if(x%2==1){
        y=ans;
    }
    else{
        y=m-ans+1;
    }
    cout<<x<<" "<<y;
    return 0;
}

