#include<bits/stdc++.h>
using namespace std;
int n,m,c[1001],f[1001],vis[1001],cnt;
string s;
void dfs(int x){
    if(x>n){
        int ans=0,t=0;
        for(int i=1;i<=n;i++){
           // cout<<f[i]<<" ";
            if(c[f[i]]<=ans){
                ans++;
                continue;
            }else{
                int u=s[i-1]-'0';
                if(u==0){
                    ans++;
                }else{
                    t++;
                }
            }
        }
      //  cout<<endl;
        if(t>=m){
            cnt++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            f[x]=i;
            vis[i]++;
            dfs(x+1);
            vis[i]--;
            f[x]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    cout<<cnt%998244353;
    return 0;
}
