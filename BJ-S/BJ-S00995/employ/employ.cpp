#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
const long long mod=998244353;
char s[N];
int c[N],a[N],xuy[N];
bool vis[N];
int n,m;
long long ans;
void DFS(int x){
    if (x>n){
        int cn=0;
        for (int i=1;i<=n;i++){
            if (c[a[i]]<=cn) cn++;
            else if (s[i]=='0') cn++;
        }
        if (n-cn+1>m) ans=(ans+1)%mod;
        return ;
    }
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            vis[i]=true;
            a[x]=i;
            DFS(x+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    bool flaga=true;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        if (s[i]=='0') flaga=false;
    }
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    if (n<=18){
        ans=0;
        DFS(1);
        cout<<ans<<endl;
    }
    else if (n==m){
        for (int i=1;i<=n;i++) if (c[i]==0) flaga=false;
        if (!flaga) cout<<0<<endl;
        else{
            ans=1;
            for (int i=1;i<=n;i++) ans=ans*i%mod;
            cout<<ans<<endl;
        }
    }
    else if (flaga){
        ans=1;
        int u=n;
        for (int i=1;i<=n;i++){
            if (c[i]==0) u--;
        }
        for (int i=1;i<=u;i++) ans=ans*i%mod;
        cout<<ans<<endl;
    }
    else{
        ans=1;
        for (int i=1;i<=n;i++) ans=ans*i%mod;
        cout<<ans<<endl;
    }
    return 0;
}
