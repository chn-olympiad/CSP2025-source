#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100009],ans,mod=998244353;
int v[100009];
void dfs(int x){
    if(x==n){
        int man=-232445;
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(v[i]){
                man=max(man,a[i]);
                cnt+=a[i];
                sum++;
            }
        }
        if(cnt>man*2&&sum>=3){
            ans++;
        }
    }else{
        v[x]=1;
        dfs(x+1);
        v[x]=0;
        dfs(x+1);
        return ;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=25){
        dfs(0);
        cout<<ans;
    }else{
        ans=1;
        for(int i=0;i<n;i++){
            ans*=2;
            ans%=mod;
        }
        int cnt=n*(n-1)/2+n;
        cnt%=mod;
        ans=ans-cnt;
        ans--;
        cout<<(ans+mod)%mod;
    }

    return 0;
}