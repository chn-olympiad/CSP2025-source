#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,p;
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)p=a[i];
    }
    sort(a+1,a+n*m+1,greater<ll>());
    if(a[1]==p){
        cout<<"1 1";
        return 0;
    }
    ll x=1,y=1;
    for(ll i=1;i<=n*m;i++){
        if(a[i]==p){
            cout<<x<<" "<<y;
            return 0;
        }
        ll nx=x,ny=y;
        if(x%2==1){
            ny++;
            if(ny>n){
                nx++;
                ny--;
            }
        }
        else{
            ny--;
            if(ny<1){
                nx++;
                ny++;
            }
        }
        x=nx;
        y=ny;
    }
    return 0;
}
