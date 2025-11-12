#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x,ll y){
    return x>y;
}
ll a[101],s[11][11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ll p=a[1];
    sort(a+1,a+n*m+1,cmp);
    ll x=1,y=1;
    ll dir=0;
    for(ll i=1;i<=n*m;i++){
        s[x][y]=a[i];
        if(dir==0){
            x++;
            if(x>n){
                dir=1;
                x--;
                y++;
            }
        }
        else if(dir==1){
            x--;
            if(x<1){
                dir=0;
                x++;
                y++;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s[i][j]==p){
                x=i;
                y=j;
            }
        }
    }
    cout<<y<<' '<<x;
    return 0;
}
