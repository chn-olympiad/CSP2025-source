#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e3+3;
bool ff[N];
int nx[N];
bool usd[N];
int jc[N];
int cnt=0;
const int mod=998244353;
void dfs(int i,int lq){
    if(i==n+1){
        if(lq>=m)cnt++;
        cnt%=mod;
        return;
    }
    if(lq>=m){
        cnt+=jc[n-i+1];
        cnt%=mod;
        return;
    }   
    for(int j=1;j<=n;j++){
        if(usd[j])continue;
        usd[j]=1;
        if(i-lq-1<nx[j]&&ff[i]){
            dfs(i+1,lq+1);
        }else{
            dfs(i+1,lq);
        }
        usd[j]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char a;
        cin>>a;
        if(a=='1')ff[i]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>nx[i];
    }
    jc[1]=1;
    for(int i=2;i<=n;i++){
        jc[i]=jc[i-1]*i;
        jc[i]%=mod;
    }
    dfs(1,0);
    cout<<cnt;
    return 0;
}