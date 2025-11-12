#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    ll op=n*m;
    ll cnt=0;
    for(ll i=1;i<=op;i++){
        cin>>a[i];
        if(i!=1){
            if(a[i]>a[1]){
                cnt++;
            }
        }
    }
    cnt++;
    ll ansi=0,ansj=0;
    for(ll j=1;j<=m;j++){
        if(j%2==1){
            for(ll i=1;i<=n;i++){
                cnt--;
                if(cnt==0){
                    ansi=i;
                    ansj=j;
                    break;
                }
            }
            if(cnt==0){
                break;
            }
        }
        if(j%2==0){
            for(ll i=n;i>=1;i--){
                cnt--;
                if(cnt==0){
                    ansi=i;
                    ansj=j;
                    break;
                }
            }
            if(cnt==0){
                break;
            }
        }
    }
    cout<<ansj<<" "<<ansi;
    return 0;
}
