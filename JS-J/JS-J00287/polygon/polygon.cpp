#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
struct j{
    ll num;
    bool aval=true;
} lst[5005];
void dfs(ll x,ll tol,ll mx){
    if(x==1){
        for(int i=1;i<=n;i++){
            if(lst[i].aval&&(lst[i].num+tol)>(2*(max(mx,lst[i].num)))){
                ans++;
            }
        }
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            if(lst[i].aval){
                lst[i].aval=false;
                dfs(x-1,tol+lst[i].num,max(mx,lst[i].num));
                lst[i].aval=true;
            }
        }
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>lst[i].num;
    }
    ll cnt=0,l=2;
    for(int i=3;i<=n;i++){
        l*=i;
        ans=0;
        dfs(i,0,0);
        ans/=l;
        cnt+=ans;
        cnt%=998244353;
    }
    cout<<cnt;
    return 0;
}
