#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,a[5005],sum[5005],cnt,maxn,f[2500005];
bool vis[2500005];
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for( int i=1;i<=n;i++ ){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1){
        ans=1;
        for( int i=1;i<=n;i++ ){
            ans*=2;
            ans%=mod;
        }
        ans=(ans-1-n-n*(n-1)/2+mod)%mod;
        cout<<ans;
        return 0;
    }
    if(n<=3){
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1;
        else cout<<0;
        return 0;
    }
    sort(a+1,a+n+1);
    for( int i=1;i<=n;i++ ){
        if(sum[i-1]>a[i]){
            memset(f,0,sizeof(f));
            memset(vis,0,sizeof(vis));
            f[0]=1;
            for( int j=1;j<i;j++ ){
                for( int k=sum[i-1];k>=a[j];k-- ){
                    f[k]=(f[k]+f[k-a[j]])%mod;
                }
            }
            for( int j=sum[i-1];j>=1;j-- ){
                if(f[j+a[i]]==0||f[j+a[i]]==1) f[j+a[i]]=(f[j+a[i]]+f[j])%mod;
                else f[j+a[i]]=f[j];
                if(f[j]!=0) vis[j+a[i]]=1;
            }
            for( int j=2*a[i]+1;j<=sum[i-1]+a[i];j++){
                if(vis[j]) ans=(ans+f[j])%mod;
            }
        }
        sum[i]=sum[i-1]+a[i];
    }
    cout<<ans;
    return 0;
}
