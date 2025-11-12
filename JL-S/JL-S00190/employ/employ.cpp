#include<bits/stdc++.h>
using namespace std;
int m,n;
long long ans=0;
int c[505],d[505],g[505];
bool f[505];
bool deter(){
    int x=0,sum=0;
    for(int i=1;i<=n;i++){
        if(d[i]==1&&g[i]>x){
            sum++;
        }
        else{
            x++;
        }
    }
    if(sum>=m){
        ans++;
        ans%=998244353;
    }
}
void dfs(int k){
    if(k>n){
        deter();
        return;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            g[k]=c[i];
            dfs(k+1);
            f[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='1') d[i]=1;
        else d[i]=0;
        cin>>c[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
