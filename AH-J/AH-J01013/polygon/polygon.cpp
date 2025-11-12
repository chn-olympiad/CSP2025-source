#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,s[5005];
void dfs(long long x,long long m,long long sum){
    if(sum+s[m-1]-s[x-1]<=a[m]) return;
    if(x==m){
        if(sum>a[m]) ans=(ans+1)%((long long)(998244353));
        return;
    }
    dfs(x+1,m,sum);
    dfs(x+1,m,sum+a[x]);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(long long i=3;i<=n;i++){
        dfs(1,i,0);
    }
    cout<<ans;
    return 0;
}
