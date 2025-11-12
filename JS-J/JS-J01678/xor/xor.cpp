#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N=500005;
int a[N],pre[N],dp[N];
map<int,int> mx,flag;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]^a[i];
    }
    flag[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i],dp[i-1]);
        if(flag[pre[i]^k])dp[i]=max(dp[i],mx[pre[i]^k]+1);
        mx[pre[i]]=max(mx[pre[i]],dp[i]);
        flag[pre[i]]=1;
    }
    printf("%lld\n",dp[n]);
    return 0;
}
