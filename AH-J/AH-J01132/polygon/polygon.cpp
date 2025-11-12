#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1001000],cnt,vis[100010];
int mod=998244353;
void dfs(int t){
    if(t==n+1){
        int tmp=0;
        for(int i=n;i>=1;i--){
            if(vis[i]){
                tmp=a[i];
                break;
            }
        }
        int tmp1=0;
        for(int i=1;i<=n;i++){
                if(vis[i]){
                   tmp1+=a[i];
                }
            }
            if(tmp1>2*tmp) cnt=(cnt+1)%mod;
            return ;
    }
    dfs(t+1);
    vis[t]=1;
    dfs(t+1);
    vis[t]=0;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==1||n==2) cout<<0;
    else if(n==3){
        if(a[1]+a[2]+a[3]>2*a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        dfs(1);
        cout<<cnt;
    }
    return 0;
}
