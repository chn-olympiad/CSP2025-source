#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int dp[maxn];
int a[maxn],sum[maxn],cnt[maxn];
priority_queue<int> q[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    bool f=false,f1=false;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]!=1)f=true;
        if(a[i]>=1)f1=true;
        sum[i]=sum[i-1]^a[i];
    }
    if(!f){
        cout<<n/2<<endl;
        return 0;
    }
    if(!f1){
        int ans=0,cnt1=0;
        if(k==0){
            for(int i=1; i<=n; i++){
                if(a[i]==0 && cnt1==0)ans++;
                else cnt1++;
                if(cnt1==2){ans++;cnt1=0;}
            }
        }else{
            for(int i=1; i<=n; i++){
                if(a[i]==1)ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(n<=100000){
        int ans=0;
        for(int i=1; i<=n; i++){
            int t=sum[i];
            cnt[t]++;
        }
        for(int i=0; i<=k; i++){
            ans+=cnt[i];
        }
        cout<<ans<<endl;
    }
    for(int i=1; i<=n; i++){
        int t=sum[i]^k;
        if(t==0){
            dp[i]=1;
        }
        if(!q[t].empty()){
            int u=q[t].top();
            dp[i]=max(dp[i],u+1);
        }
        q[t].push(dp[i]);
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
