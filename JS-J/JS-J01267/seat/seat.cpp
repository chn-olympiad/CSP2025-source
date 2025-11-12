#include<bits/stdc++.h>
using namespace std;
#define ll long long
void IOS(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
}
ll a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    IOS();
    ll n,m,t,a1;
    cin>>n>>m;
    t=n*m;
    for(ll i=1;i<=t;i++){
        cin>>a[i];
    }
    a1=a[1];
    sort(a+1,a+1+t);
    ll seat=t-(lower_bound(a+1,a+1+t,a1)-a)+1;
    ll lie=ceil(seat*1.0/n),hang;
    if(lie%2==1){
        hang=seat-(lie-1)*n;
    }
    else{
        hang=n-(seat-(lie-1)*n)+1;
    }
    cout<<lie<<" "<<hang;
    return 0;
}
