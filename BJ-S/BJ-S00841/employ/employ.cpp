#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353;
int n,m,cnt,a[N],vis[N],ans,flag,l,kl,kk;long long f[N];
string s;
void dfs(int x){
    if(n-cnt<m)return;
    if(x==n){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        if(s[x]=='0'||cnt>=a[i])cnt++;
        dfs(x+1);
        vis[i]=0;
        if(s[x]=='0'||cnt>a[i])cnt--;
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!a[i])kk++;
    }
    sort(a+1,a+n+1);
    l=INT_MAX;
    kl=0;
    for(int i=0;i<n;i++)
        if(s[i]==48)flag=1;
        else{
            l=min(l,i);
            kl=1;
        }
    if(!kl)ans=0;
    else if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>l){
                l=i;
                break;
            }
        }
        n--,l--;
        f[0]=1;
        for(int i=1;i<=n;i++)f[i]=f[i-1]*i%M;
        ans=f[n]*(n-l)%M;
    }
    else if(n==m){
        if(flag||kk)ans=0;
        else{
            f[0]=1;
            for(int i=1;i<=n;i++)f[i]=f[i-1]*i%M;
            ans=f[n];
        }
    }
    else if(flag)dfs(0);
    else{
        if(n-kk>=m){
            f[0]=1;
            for(int i=1;i<=n;i++)f[i]=f[i-1]*i%M;
            ans=f[n];
        }else ans=0;
    }
    cout<<ans<<'\n';
    return 0;
}