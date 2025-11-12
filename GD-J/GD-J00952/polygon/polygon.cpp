#include <bits/stdc++.h>
using namespace std;
const long long maxn=5e3+10,mod=998244353;
long long z[maxn],n,cnt=0;
void dfs(long long s,long long num,long long ma,long long p){
    if(s==n+1){
        return ;
    }long long ts=num+z[s],tp=p+1;
    long long temp=max(ma,z[s]);
    if(ts>temp*2&&tp>=3){
        cnt=(cnt+1)%mod;
    }dfs(s+1,num,ma,p);
    dfs(s+1,ts,temp,tp);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>z[i];
    }dfs(1,0,0,0);
    cout<<cnt;
    return 0;
}

