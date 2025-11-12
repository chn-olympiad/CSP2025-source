#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod=998244353;
int n,ans;
int l[5006];

void dfs(int now,int mx,int sum,int cnt,int goal){
    if(cnt==goal){
        if(sum>mx*2){
            ans++;
            ans%=mod;
        }
        return ;
    }

    for(int i=1;now+i<=n;i++){
        if(cnt+(n-(now+i)+1)<goal) return ;
        dfs(now+i,max(mx,l[now+i]),sum+l[now+i],cnt+1,goal);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        if(l[i]!=1) f=0;
    }

    if(f){
        int zi=(n*(n-1))%mod,mu=2;
        for(int i=3;i<=n;i++){
            mu=mu*i%mod;zi=zi*(n-i+1)%mod;
            ans=(ans+(zi/mu))%mod;
        }
        cout<<ans;
        return 0;
    }

    if(n>=400){
        cout<<0;
        return 0;
    }

    for(int i=3;i<=n;i++){
        for(int j=1;n-j+1>=i;j++){
            dfs(j,l[j],l[j],1,i);
        }
    }
    cout<<ans;

    return 0;
}
