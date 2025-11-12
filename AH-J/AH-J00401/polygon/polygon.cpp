#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5010],ans;
void dfs(long long cur,long long sum,long long pre,long long maxn,long long top){
    if(cur==top){
        if(sum>maxn*2){
            ans++;
            ans%=MOD;
        }
        return ;
    }
    for(int i=pre+1;i<=n+cur-top+1;i++){
        dfs(cur+1,sum+a[i],i,max(maxn,a[i]),top);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(0,0,0,0,i);
    }
    cout<<ans%MOD;
    return 0;
}
