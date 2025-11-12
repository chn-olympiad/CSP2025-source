#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
long long n,a[5200],ans,v[5200];
void dfs(long long sum,long long maxn,long long tot){
    if(tot==n)return;
    if(tot>=3&&sum>2*maxn){
        ans++;ans%=mo;
    }
    for(int i=1;i<=n;i++){
        dfs(sum+a[i],max(maxn,a[i]),tot+1);
        dfs(sum,maxn,tot);
    }
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<3){
        cout<<0;
        exit(0);
    }
    if(n==3){
        long long sum=0,maxn=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
        if(2*maxn<sum)cout<<1;
        else cout<<0;
        exit(0);
    }
    dfs(0,0,0);
    cout<<ans;
}
