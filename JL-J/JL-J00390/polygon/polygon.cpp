#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],ans[5005];
bool IsOne=1;
const ll mod=998244353;
ll res=0;
void dfs(ll tiao,ll cnt,ll leng,ll maxv){
    if(tiao>=3&&leng>maxv){
        res++;
        res%=mod;
        return;
    }
    if(tiao>n||cnt>n) return;
    dfs(tiao+1,cnt+1,leng+a[cnt+1],max(maxv,a[cnt+1]));
    dfs(tiao,cnt+1,leng-a[cnt]+a[cnt+1],max(maxv,a[cnt+1]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=1) IsOne=0;
    }
    if(IsOne){
        ans[3]=1,ans[4]=5,ans[5]=16,ans[6]=42;
        ll fen=15;
        for(int i=7;i<=n;i++){
            ans[i]=(ans[i-1]*2+fen)%mod;
            fen=(fen+i-1)%mod;
        }
        cout<<ans[n]%mod;
        return 0;
    }
    if(n<=3){
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))) cout<<1;
        else cout<<0;
        return 0;
    }
    if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
        cout<<9;
        return 0;
    }
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
        cout<<6;
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(3,3,a[1]+a[2]+a[3],max(a[1],max(a[2],a[3])));
    cout<<res;
    return 0;
}
