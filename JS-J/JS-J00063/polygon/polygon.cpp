#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
const ll mod=998244353;
int n,a[N],ans,s[N];
ll f[N],C[N][N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    C[0][0]=1;
    for(int i=1;i<=5000;i++){
        C[i][0]=1;
        for(int j=1;j<=5000;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    scanf("%d",&n);
    if(n==1||n==2){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    f[0]=1;
    for(int i=2;i<=n;i++){
        for(int j=s[i-1];j>=a[i-1];j--){
            f[j]=(f[j]+f[j-a[i-1]])%mod;
        }
        if(i>=3){
            ll sum1=0,sum2=0;
            for(int j=0;j<=i-1;j++){
                sum1=(sum1+C[i-1][j])%mod;
            }
            for(int j=0;j<=a[i];j++){
                sum2=(sum2+f[j])%mod;
            }
            ans=(ans+sum1-sum2+mod)%mod;
        }

    }
    printf("%lld",ans);
}
