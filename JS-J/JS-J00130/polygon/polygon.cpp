#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,num;
vector<ll>ls;
bool used[5005];
ll n,a[5005];

ll dans,dmax,pdmax;
bool check(){
    return 1;
}
void dfs(ll x){
    if(x==0){
        if(check()) num++;
        return ;
    }
    for(ll i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            dans+=a[i];
            if(a[i]>dmax){
                pdmax=dmax;
                dmax=a[i];
            }
            dfs(x-1);
            used[i]=0;
            dans-=a[i];
            dmax=pdmax;

        }
    }
    return ;
}
ll mu(int x){
    ll num=1;
    for(ll i=x;i>=2;i++){
        num*=i;
    }
    return num;
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);

    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",a[i]);
    }
    for(ll i=3;i<=n;i++){
        dans=dmax=pdmax=0;
        memset(used,0,sizeof(used));
        num=0;
        dfs(i);
        ans+=num/mu(i);
    }
    cout<<ans;
    return 0;
}
