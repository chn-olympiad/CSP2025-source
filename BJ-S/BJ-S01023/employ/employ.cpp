#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[505],p[505],ans;
char s[505];
bool vis[505];
void dfs(long long x){
    if(x==n+1){
        long long sum=0;
        for(int b=1;b<=n;b++)if(!(s[b]-'0') || a[p[b]]<=sum)sum++;
        if(n-sum>=m)ans++;
        return;
    }
    for(int b=1;b<=n;b++){
        if(!vis[b]){
            vis[b]=1;
            p[x]=b;
            dfs(x+1);
            vis[b]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld%s",&n,&m,s+1);
    for(int b=1;b<=n;b++)cin>>a[b];
    if(m==n){
        ans=1ll;
        for(long long b=1;b<=n;b++){
            if(s[b]=='0' || !a[b]){
                cout<<0;
                return 0;
            }
            ans=ans*b%mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}