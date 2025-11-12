#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long pd[500005];
long long ans=0;
void dfs(long long idx,long long sum,long long maxn,long long num){
    if(idx==num){
        if(sum>maxn*2){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    for(long long i=idx;i<=n;i++){
        if(pd[i]==0){
            pd[i]=1;
            dfs(i,sum+a[i],max(a[i],maxn),num);
            pd[i]=0;
        }
    }
    return ;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long tp=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            tp++;
        }
    }
    if(tp==n){
        for(long long i=3;i<=n;i++){
            long long cnt=1;
            for(long long j=0;j<i;j++){
                cnt=cnt*(n-j)%998244353;
            }
            for(long long j=1;j<=i;j++){
                cnt/=j;
            }
            ans=(ans%998244353+cnt%998244353)%998244353;
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+n+1);
        for(long long i=3;i<=n;i++){
            dfs(1,0,0,i);
        }
        ans%=998244353;
        cout<<ans;
    }
    return 0;
}
