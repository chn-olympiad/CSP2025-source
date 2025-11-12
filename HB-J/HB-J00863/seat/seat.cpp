#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[105],b[15][15],cnt=1,k,w=1;
//vector<ll> v;
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) k=a[i];
        else{
            if(a[i]>k) w++;
        }
    }
    for(ll i=1;i<=m;i++){
        if(i%2==1){
            for(ll j=1;j<=n;j++){
                b[j][i]=cnt;
                cnt++;
            }
        }
        else{
            for(ll j=n;j>=1;j--){
                b[j][i]=cnt;
                cnt++;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(b[i][j]==w){
                cout<<j<<" "<<i;
                return ;
            }
        }
    }
    return ;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
