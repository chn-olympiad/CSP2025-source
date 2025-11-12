#include<bits/stdc++.h>
using namespace std;
int n,m,s[550];
string ss;
int c[550];
long long ans=0;
bool us[550];
void dfs(int st,int nu,int nm){
    if(st>n){
        if(nm>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(us[i]) continue;
        us[i]=1;
        if(nu>=c[i]) dfs(st+1,nu+1,nm);
        else if(s[st]==1) dfs(st+1,nu,nm+1);
        else dfs(st+1,nu+1,nm);
        us[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>ss;
    for(int i=0;i<ss.size();i++) s[i+1]=ss[i]-'0';
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1,0,0);
    cout<<ans%998244353;
    return 0;
}
