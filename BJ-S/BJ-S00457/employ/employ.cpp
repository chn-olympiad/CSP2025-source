#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
const int mod=998244353;
int n,m,c[maxn],vis[maxn],p[maxn],d[maxn];
long long ans=0;
string s;
void dfs(int step){
    if(step>n){
        int k=0;
        for(int i=1;i<=n;i++){
            if(c[p[i]]>d[i]&&s[i-1]!='0'){
                k++;
            }
            //cout<<p[i]<<" ";
        }
        //cout<<endl<<k<<endl;
        if(k>=m) ans=(ans+1)%mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1,p[step]=i;
        dfs(step+1);
        vis[i]=0,p[step]=0;
    }
}
int main(int argc,char** argv){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int tmp=0;
    for(int i=0;i<n;i++){
        d[i+1]=tmp;
        if(s[i]=='0') tmp++;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
