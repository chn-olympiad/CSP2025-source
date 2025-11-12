#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100+10;
ll n,m,a[N],ans;
bool cmp(const ll &x,const ll &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++) cin>>a[i];
    ans=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            if(a[(i-1)*m+j]==ans){
                if(i%2==0) cout<<i<<' '<<m-j+1;
                else cout<<i<<' '<<j;
            }
    return 0;
}
