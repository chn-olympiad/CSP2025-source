#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5001];
ll n;
ll cnt;
void solve(ll dep,ll sum,ll maxn){
    if(dep==n+1){
        if(sum<=maxn*2){
            return;
        }
        cnt++;
        cnt%=998244353;
        return;
    }
    for(ll i=0;i<=1;i++){
        if(i==0){
            solve(dep+1,sum,maxn);
        }
        else{
            solve(dep+1,sum+a[dep],max(maxn,a[dep]));
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    solve(1,0,0);
    cout<<cnt%998244353;
    return 0;
}
