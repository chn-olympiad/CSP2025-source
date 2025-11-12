#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],b[5010],f[60010],g[60010];
long long ans,cnt;
inline void lu(){
    f[0]=1LL;
    cnt=1LL;
    int www=0;
    for(int i=1;i<=n;i++)
        www=max(www,a[i]);
    for(int i=1;i<=n;i++){
        ans+=cnt;
        ans%=mod;
        //printf("%lld\n",a[i]);
        //printf("%lld\n",ans);
        for(int j=0;j<=a[i];j++){
            ans-=1LL*f[j];
            ans%=mod;
            while(ans<0LL) ans+=mod;
            //printf("%lld %lld\n",ans,f[j]);
        }
        //printf("%lld\n\n",ans);
        cnt*=2LL;
        cnt%=mod;
        for(int j=0;j<=www;j++){
            if(f[j]==0) continue;
            g[j]+=f[j];
            g[j]%=mod;
            if(j+a[i]<=www){
                g[j+a[i]]+=f[j];
                g[j+a[i]]%=mod;
            }
        }
        for(int j=0;j<=www;j++){
            f[j]=g[j];
            g[j]=0LL;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //nice
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    /*for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    puts("");*/
    if(b[n]>=60000){
        lu();
        return 0;
    }
    f[0]=1LL;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=b[i-1];j++){
            if(f[j]==0) continue;
            g[j]+=f[j];
            g[j]%=mod;
            g[j+a[i]]+=f[j];
            g[j+a[i]]%=mod;
        }
        for(int j=a[i]+1;j<=b[i-1];j++){
            ans+=f[j];
            ans%=mod;
        }
        for(int j=0;j<=b[i];j++){
            f[j]=g[j];
            g[j]=0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
