#include<bits/stdc++.h>
using namespace std;
const int K=998244353;
int n,m;
string s;
int c[505];
bool vis[505];
long long ans;
void dfs(int cnt,int t,int pos){
    if(cnt==m){
        long long s=1;
        for(int i=2;i<=(n-pos+1);i++){
            s*=i;
        }
        ans+=s;
        if(ans>=K) ans-=K;
        return ;
    }
    if(pos>n) return ;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(s[pos-1]=='0'){
            vis[i]=1;
            dfs(cnt,t+1,pos+1);
            vis[i]=0;
        }
        else{
            vis[i]=1;
            if(c[i]>t){
                dfs(cnt+1,t,pos+1);
            }
            else{
                dfs(cnt,t+1,pos+1);
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
        cin>>c[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
