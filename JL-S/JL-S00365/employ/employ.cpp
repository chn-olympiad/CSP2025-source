#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],sum[N],vis[N];
int n,m;
int ans=0;
int mod=998244353;
void dfs(int now,int cnt){
    if(now==n+1&&cnt>=m){
            ans=(ans+1)%mod;
            return ;
    }
    else{
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            vis[i]=1;
            if(a[i]<=sum[now]){
                dfs(now+1,cnt);
            }
            else dfs(now+1,cnt+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')sum[i+1]=sum[i]+1;
        else sum[i+1]=sum[i];
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')sum[i+1]=0x3f3f3f3f;
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
