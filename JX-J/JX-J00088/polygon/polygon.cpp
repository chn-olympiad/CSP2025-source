#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005];
int sum,ans;
void dfs(int c,int l,int cnt){
    if(c>n){
        return;
    }
    if(l+a[c]>2*a[c]){
        if(cnt>=2){
            ans++;
            ans%=mod;
        }
    }
    dfs(c+1,l+a[c],cnt+1);
    dfs(c+1,l,cnt);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool k=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            k=false;
        }
    }
    if(k){
        int f[5005];
        f[3]=(n*(n-1)*(n-2))/6%mod;
        ans+=f[3];
        for(int i=4;i<=n;i++){
            f[i]=f[i-1]*(n-i+1)/i;
            ans+=f[i];
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    dfs(1,0,0);
    cout<<ans;
}