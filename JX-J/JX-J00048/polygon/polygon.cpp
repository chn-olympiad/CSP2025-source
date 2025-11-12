#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,MOD=998244353;
int n,a[N],ans;
void dfs(int k,int sum,int maxx,int cnt){
    if(k==n+1){
        if(sum>maxx*2&&cnt>=3){
            ans++,ans%=MOD;
            // cout<<k<<' '<<sum<<' '<<maxx<<' '<<cnt<<'\n';
        } 
        return ;
    }
    // dfs(k+1,sum,maxx,cnt);
    for(int i=k;i<=n;i++){
        dfs(i+1,sum+a[i],max(maxx,a[i]),cnt+1);
        dfs(i+1,sum,maxx,cnt);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3){
        int sum=a[1]+a[2]+a[3];
        if(sum>max({a[1],a[2],a[3]})*2) cout<<1<<'\n';
        else cout<<0<<'\n';
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans<<'\n';
    return 0;
}