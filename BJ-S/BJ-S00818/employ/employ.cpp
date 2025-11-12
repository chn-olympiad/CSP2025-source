#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,box[505],vis[505],a[505],s[505],ans,m,cntn;
void dfs(int x){
    if(x>n){
        int cnt=0,tot=0;
        for(int i=1;i<=n;i++){
            if(tot>=a[box[i]]){
                tot++;
                continue;
            }
            if(s[i]==1){
                cnt++;
            }else{
                tot++;
            }
        }
        if(cnt>=m){
            ans++;
            ans=ans%mod;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            box[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string st;
    cin>>st;
    for(int i=1;i<=n;i++){
        s[i]=st[i-1]-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
}
