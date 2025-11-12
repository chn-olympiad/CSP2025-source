#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int t[505],vis[505],q[505],l[505],ok[505];
int n,m,ans,po,pkk;
string s;
void dfs(int x){
    //cout<<x<<" "<<ans<<endl;
    if(x==n+1){
        //cout<<ans<<" "<<po<<endl;
        //for(int i=1;i<=n;i++)cout<<ok[i]<<" ";
        //cout<<endl;
        if(ans>=m){
            pkk++;
            pkk%=mod;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            int pk=0;
            if(po>=t[i]||s[x-1]=='0')po++,pk=1;
            else ans++;
            ok[x]=i;
            dfs(x+1);
            if(pk)po--;
            else ans--;
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    //cout<<s<<endl;
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<=n;i++)q[i]=s[i-1]-'0';
    //for(int i=1;i<=n;i++)cout<<q[i]<<" ";
    //cout<<endl;
    if(s.find("0")==-1){
        int cnt=1;
        for(int i=n;i>=1;i--){
            cnt*=i;
            cnt%=mod;
        }
        cout<<cnt;
    }
    else{
        dfs(1);
        cout<<pkk;
    }
    return 0;
}
