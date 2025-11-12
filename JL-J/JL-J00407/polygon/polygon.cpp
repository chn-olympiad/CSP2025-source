#include<bits/stdc++.h>
using namespace std;
int a[5010];
const int mod=998244353;
int ans=0;
void dfs(int sum,int k,int id,int index){
    if(sum>k){
        ans=(ans+1)%mod;
    }
    for(int i=index;i<id;i++){
        dfs(sum+a[i],k,id,i+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int maxn=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*2%mod;
        }
        ans=(ans+mod-n*(n-1)/2-n-1)%mod;
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--) dfs(0,a[i],i,1);
    cout<<ans;
    return 0;
}
