#include<bits/stdc++.h>
using namespace std;

const long long N=5005,MOD=998224353;
long long n;
long long a[N];
long long ans;
long long sum;

void dfs(int x,int idx){
    if(x>=3){
        long long ansL=idx+1;
        long long ansR=lower_bound(a+idx,a+1+n,sum)-a-1;
        if(ansL<=ansR)ans=(ans+(ansR-ansL+1))%MOD;
    }
    for(int i=idx+1;i<=n-1;++i){
        sum+=a[i];
        dfs(x+1,i);
        sum-=a[i];
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    dfs(1,0);
    cout<<ans;
    return 0;
}