#include<bits/stdc++.h>
using namespace std;
long long a[5010],num[5010],n,ans;
void dfs(long long t, long long sum){
    if(t>n){
        if(sum<3) return;
            long long maxn=-1,len=0;
        for(long long i=1;i<=sum;i++){
            maxn=max(maxn,num[i]);
            len+=num[i];
        }
        if(len>maxn*2) ans++;
        ans%=998244353;
        return;
    }
    dfs(t+1,sum);
    num[sum]=a[t];
    dfs(t+1,sum+1);
    num[sum]=0;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i];
    dfs(1,1);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
return 0;
}
