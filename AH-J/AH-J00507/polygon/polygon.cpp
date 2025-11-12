#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[5005];
bool v[5005];
ll sum=0;
void dfs(ll mb,ll in,ll num,ll mx,ll xb){
    if(in==mb){
        if(num>mx*2){
            sum++;
            sum=sum%998244353;
        }
        return ;
    }
    for(ll i=xb+1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            dfs(mb,in+1,num+a[i],max(mx,a[i]),i);
            v[i]=0;
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
    for(ll i=3;i<=n;i++){
        dfs(i,0,0,0,0);
    }
    cout<<sum;
    return 0;
}
