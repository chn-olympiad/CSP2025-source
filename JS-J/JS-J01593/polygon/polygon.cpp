#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n;
long long ans;
bool S;
int a[100005];
void dfs(int dep,int zd,int sum,int gs){
    if(dep>n){
        if(zd*2<sum&&gs>=3) ans=(ans+1)%Mod;
        return;
    }
    dfs(dep+1,max(zd,a[dep]),sum+a[dep],gs+1);
    dfs(dep+1,zd,sum,gs);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) S=1;
    }
    if(S==0){
        ans=1;
        for(int i=1;i<=n;i++)
            ans=ans*2%Mod;
        cout<<ans-1-n-n*(n-1)/2<<endl;
        return 0;
    }
    ans=0;
    dfs(1,0,0,0);
    cout<<ans<<endl;
    return 0;
}
