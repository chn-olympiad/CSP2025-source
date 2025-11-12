#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int mod=998244353;
int a[N],f[N],t[N];
bool vis[N];
int n,ans,sum,TS;
bool fa=1;
void dfs(int sum,int maxn,int lst,int tot){
    if(maxn*2<sum&&tot>=3) ans++;
    if(lst==n+1) return ;
    for(int i=lst;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        f[tot]=i;
        dfs(sum+a[i],max(maxn,a[i]),i+1,tot+1);
        vis[i]=0;
    }
    return ;
}
int pffa(int x){
    return x*(x-1)/2%mod;
}
int qpow(int a,int k){
    int s=1;
    while(k>0){
        if(k&1) s=(s*a)%mod;
        k>>=1;
        a=(a*a)%mod;
    }
    return s;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) fa=0;
        t[a[i]]++;
    }
    if(fa){
        cout<<qpow(2ll,n)-pffa(n)-n-1;
        return 0;
    }
    if(n<=27){
        dfs(0,0,1,1);
        cout<<ans%mod;
        return 0;
    }
    for(int i=1;i<=5000;i++){
        TS+=t[i];
        if(!t[i]) continue;
        t[i]--;
        for(int j=1;j<=i;j++){
            if(!t[j]) continue;
            t[j]--;
            for(int k=1;k<=i;k++){
                if(j+k<i) continue;
                if(!t[k]) continue;
                ans+=qpow(2ll,TS-3);
            }
            t[j]++;
        }
        t[i]++;
    }
    cout<<ans%mod;
    return 0;
}
