#include<bits/stdc++.h>
using namespace std;
int n,m,d;
long long ans,g;
string s;
int c[505];
bool vis[505];
const int mod=998244353;
int dfs(int step){
    if(step>=n){
        if(g>=m){
            (ans++)%mod;
        }
        return 0;
    }
    for(int i=step;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(c[i]<=d||s[i]=='1'){
                dfs(step+1);
            }
            else{
                g++;
                dfs(step+1);
            }
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    dfs(1);
    cout<<ans%mod;

    return 0;
}
