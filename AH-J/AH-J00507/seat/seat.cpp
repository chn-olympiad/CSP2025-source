#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,s;
ll a[15];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
    for(ll i=1;i<=s;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+s+1,cmp);
    ll x=1,y=1;
    ll b=1;
    for(ll i=1;i<=s;i++){
        if(a[i]==k){
            break;
        }
        x+=b;
        if(x>n||x<1){
            y++;
            if(b==1){
                b=-1;
            }else if(b==-1){
                b=1;
            }
            x=x+b;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
