#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[505];
bool vis[505];
string s;
void dfs(int x,int cnt,int sum){
    if(cnt==n && sum>=m){
        ans++;
        ans%=998244353;
        return;
    }
    for(int i=1;i<=n;i++){
        if(cnt-sum>=a[i] || vis[i]) continue;
        vis[i]=1;
        if(s[cnt]=='1') dfs(i,cnt+1,sum+1);
        else dfs(i,cnt+1,sum);
        vis[i]=0;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}