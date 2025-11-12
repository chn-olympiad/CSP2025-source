#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],f[505],vis[505],flagA=1;
long long ans;
string str;
const long long mod=998244353;
void dfs(int x){
    if(x>n){
        int cntwn=0,cntls=0;
        for(int i=1;i<=n;i++){
            if(cntls>=a[f[i]]||str[i-1]=='0'){
                cntls++;
            }
            else{
                cntwn++;
            }
        }
        if(cntwn>=m){
            ans++;
            ans%=mod;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            continue;
        }
        f[x]=i;
        vis[i]=1;
        dfs(x+1);
        vis[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(str[i]=='0'){
            flagA=0;
        }
    }
    if(n<=10){
        dfs(1);
        cout<<ans;
    }
    else if(flagA){
        ans=1;
        for(long long i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
    }
    else if(m==1){
        int p=-1;
        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                p=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]>p){
                ans++;
            }
        }
        for(long long i=1;i<n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans;
    }
    else{
        cout<<0;
    }
    return 0;
}
