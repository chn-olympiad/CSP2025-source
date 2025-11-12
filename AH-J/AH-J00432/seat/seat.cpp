#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1050],ans[110][110];
bool cmp(const ll &x,const ll &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ll c=1,pos=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(ll j=1;j<=m;j++){
        if(j%2!=0){
            for(ll i=1;i<=n;i++){
                ans[i][j]=a[c];
                c++;
            }
        }
        else{
            for(ll i=n;i>=1;i--){
                ans[i][j]=a[c];
                c++;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(ans[i][j]==pos){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
