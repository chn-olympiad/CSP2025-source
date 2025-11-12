#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long mod=998244353;
ll n,m,c[1005],ans,vis[1005],a[1005];
string s;
void dfs(int x){
    if(x==n+1){
        ll cnt=0,ct=0;
        for(int i=1;i<=n;i++){
                //cout<<a[i]<<' ';
            if(c[a[i]]>cnt&&s[i]=='1'){
                ct++;
            }else{
                cnt++;
            }
        }
        //cout<<endl<<ct<<' '<<cnt<<endl;
        if(ct>=m)ans++;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            a[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    cout<<ans%mod;
    return 0;
}
//
