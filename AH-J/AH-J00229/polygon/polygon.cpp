#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
void dfs(int x,int sum,int mx){
    if(x==n+1){
        if(sum>2*mx){
            ans=(ans+1)%998244353;
        }
        return ;
    }
    dfs(x+1,sum+a[x],max(mx,a[x]));
    dfs(x+1,sum,mx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    cout<<ans%998244353;
    return 0;
}
