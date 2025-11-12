#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[105],k;
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++) cin>>a[i];
    ll t=a[1],x=1,y=1,o=0;
    sort(a+1,a+(n*m)+1,cmp);
    for(ll i=1;i<=n*m;i++){
        if(a[i]==t){
            t=i;
            break;
        }
    }
    for(ll i=1;i<=n*m;i++){
        k++;
        if(k==t){
            cout<<x<<' '<<y;
            break;
        }
        if(o==0){
            y++;
            if(y>n){
                y--,x++;
                o=1;
            }
        }else if(o==1){
            y--;
            if(y==0){
                y++,x++;
                o=0;
            }
        }
    }
    return 0;
}
