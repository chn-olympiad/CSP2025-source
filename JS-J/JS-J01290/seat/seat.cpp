#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[110];
struct Seat{
    ll x;
    ll y;
}seat[110];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    cin>>a[1];
    ll r=a[1];
    ll cnt=n*m;
    for(ll i=2;i<=cnt;i++){
        cin>>a[i];
    }
    ll num=0;
    sort(a+1,a+cnt+1);
    for(ll j=1;j<=m;j++){
        if(j%2==1){
            for(ll i=1;i<=n;i++){
                num++;
                seat[num].x=i;
                seat[num].y=j;
            }
        }
        else{
            for(ll i=n;i>=1;i--){
                num++;
                seat[num].x=i;
                seat[num].y=j;
            }
        }
    }
    ll flag;
    for(ll i=cnt;i>=1;i--){
        if(a[i]==r){
            flag=cnt-i+1;
            break;
        }
    }
    cout<<seat[flag].y<<" "<<seat[flag].x;

    return 0;
}
