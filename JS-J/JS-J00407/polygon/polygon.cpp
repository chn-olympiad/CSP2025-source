#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005];
long long ans=0;
void dfs(int i,int j,int pls){
    if(pls>a[i]*2){
        ans=(ans+(1<<(j-1)))%MOD;
        return;
    }
    if(j==1){
        if(pls>a[i]*2){
            ans=(ans+1)%MOD;
        }
        return;
    }
    dfs(i,j-1,pls);
    dfs(i,j-1,pls+a[j-1]);
    return;


    for(int jj=j-1;j>=1;j--){
        dfs(i,jj,pls+a[jj]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=3;i--){
        dfs(i,i,a[i]);
    }
    cout<<ans%MOD;
    return 0;
}
