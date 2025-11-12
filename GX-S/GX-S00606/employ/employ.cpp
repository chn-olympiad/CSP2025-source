#include<bits/stdc++.h>
using namespace std;
long long n,m,s[255],c[255],vis[255],ans,fct[255];string k;
void dfs(long long p,long long ca){
    if((p-ca)>=m){
        ans+=fct[(n-p)];
        ans%=998244353;
        return;
    }
    if((m+ca)>n){
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){

            vis[i]=1;
            if(ca>=c[i]||s[p+1]==0){
                dfs(p+1,ca+1);
            }else{
                dfs(p+1,ca);
            }

            vis[i]=0;
        }
    }
}//freopen my luogu name is gaogao05
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fct[0]=1;
    for(int i=1;i<=19;i++){
        fct[i]=fct[i-1]*i;
        fct[i]%=998244353;
    }
    cin>>n>>m;
    cin>>k;
    for(int i=0;i<n;i++){
        s[i+1]=k[i]-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    dfs(0,0);
    cout<<ans;
    return 0;
}
//freopen stwout Nevergonnagive you up
//my luogu name is gaogao05.
