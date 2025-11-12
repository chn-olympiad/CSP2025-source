#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,R,cnt=1,l,c;
    cin>>n>>m>>R;
    for(ll x,i=1;i<n*m;i++){
        cin>>x;
        if(x>R) cnt++;
    }
    c = cnt / n + 1;
    if(c&1)
        l = ((cnt%n==0)?(n):(cnt%n));
    else
        l = n + 1 -(cnt%n);
    cout<<c<<" "<<l;
    return 0;
}
