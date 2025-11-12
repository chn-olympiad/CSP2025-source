#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,y[5010][5010],mod=998244353;
void dfs(long long x,long long num,long long maxx,long long pos){
    if(x==n+1){
        if(num>2*maxx&&pos>=3)ans=(ans+1)%mod;
        return;
    }
    if(!(pos+n-x<3))
    dfs(x+1,num,maxx,pos);
    dfs(x+1,num+a[x],max(maxx,a[x]),pos+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(a[n]==1){
        y[1][1]=1;
        for(int i=2;i<=n+1;i++){
            for(int j=1;j<=i;j++){
                y[i][j]=(y[i-1][j-1]+y[i-1][j])%mod;
            }
        }
        for(int i=4;i<=n+1;i++){
            ans=(ans+y[n+1][i])%mod;
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
