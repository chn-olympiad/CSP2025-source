#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],maxn,b[5005],sum,sumn,ans;
void dfs(int x){
    if(x==n+1){
        maxn=0;
        sum=0;
        sumn=0;
        for(int i=1;i<=n;i++){
            if(b[i]){
                sumn++;
                sum+=a[i];
                maxn=max(maxn,a[i]);
            }
        }
        if(sumn>=3&&sum>maxn*2){
            ans=(ans+1)%mod;
        }
        return ;
    }
    dfs(x+1);
    b[x]=1;
    dfs(x+1);
    b[x]=0;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        for(int i=3;i<=n;i++){
            ans=(ans+(n-i+1)%mod)%mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
