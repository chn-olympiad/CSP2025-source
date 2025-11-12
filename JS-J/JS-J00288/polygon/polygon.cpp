#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],dp,ans;
void dfs(long long s,long long x,long long c){
    if(s==x-1){
        if(c>a[x]) dp++;
        return ;
    }
    dfs(s+1,x,c+a[s+1]);
    dfs(s+1,x,c);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(long long i=3;i<=n;i++){
        dp=0;
        dfs(0,i,0);
        ans+=dp;
    }
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
