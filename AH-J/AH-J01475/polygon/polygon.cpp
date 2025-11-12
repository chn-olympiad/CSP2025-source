#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010,MOD=998244353;
int n,maxa=0;
int a[N];
int dp[N*N],d2[N*2],d1[N];
ll ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxa=max(maxa,a[i]);
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    if(maxa<=1){
        ll pow2=1;
        for(int i=1;i<=n-1;i++) pow2=pow2*2%MOD;
        cout<<n%MOD*(pow2+MOD-1-(n-1))%MOD<<endl;
        return 0;
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[a[i]]+=1;
        for(int j=N*N-10;j>=1;j--){
			if(j-a[i]>=0) dp[j]=(dp[j]+dp[j-a[i]])%MOD;
		}
    }
    for(int i=1;i<=n;i++) d1[a[i]]++;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            d2[a[i]+a[j]]++;
        }
    }
    /*for(int i=1;i<=maxa*2;i++){
        cout<<((dp[i]+MOD- (i<=N*2-10?d2[i]:0) )%MOD+MOD- (i<=N-5?d1[i]:0) )%MOD<<' ';
    }*/
    for(int i=1;i<=N*N-10;i++){
        dp[i]=((dp[i]+MOD- (i<=N*2-10?d2[i]:0) )%MOD+MOD- (i<=N-5?d1[i]:0) )%MOD;
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=a[i]*2+1;j<=N*N-10;j++) sum=(sum+dp[j])%MOD;
        ans=(ans+sum)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
