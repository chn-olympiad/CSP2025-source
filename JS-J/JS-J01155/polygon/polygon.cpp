#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n;
int a[5005];
long long ans;
void dfs(int dep,long long maxa,long long sum,int cho){
    if(dep>=n+1){
        if(cho>=3&&(sum>2*maxa)){
            ans=(ans+1)%mod;
        }
        return ;
    }
    dfs(dep+1,maxa,sum,cho);
    dfs(dep+1,max(maxa,1ll*a[dep]),sum+a[dep],cho+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
