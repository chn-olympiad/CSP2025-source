#include<bits/stdc++.h>
using namespace std;
string r;int k[50],n,m,use[50],ans,p=998244353,fact[50];
void dfs(int id,int m0,int f){
    if(m0>=m){
        (ans += fact[n-id]) %= p;
        return;
    }
    if(id==n){
        return;
    }
    for(int i=0;i<n;i++){
        if(!use[i]){
            use[i]=1;
            if(f>=k[i] || r[id]=='0')dfs(id+1,m0,f+1);
            else dfs(id+1,m0+1,f);
            use[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    fact[0]=1;
    for(int i=1;i<40;i++)
        fact[i] = fact[i-1] * i % p;
    dfs(0,0,0);
    cout<<ans;
}
