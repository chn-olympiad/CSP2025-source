#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=5005;
int a[N],dp[N];
int ksm(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1)res=(res*a)%p;
        b>>=1,a=(a*a)%p;
    }
    return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        for(int j=0;j<=a[i];j++)dp[j]=0;
        dp[a[i]]=1;
        for(int j=1;j<i;j++){
            for(int k=0;k<=a[i]-a[j];k++)
                dp[k]+=dp[k+a[j]];
        }
        int cnt=0;
        for(int j=0;j<=a[i];j++)cnt+=dp[j];
        ans=(ans+(ksm(2,i-1,MOD)-cnt%MOD+MOD)%MOD)%MOD;
    }
    printf("%lld\n",ans);
	return 0;
}
