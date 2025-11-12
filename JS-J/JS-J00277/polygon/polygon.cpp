#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+4,inf=1e9+7,mod=998244353;
int n,ans,wkq,wdl,wyj,wgm,a[maxn];
void dfs(int st,int cnt,int sum,int maxm)
{
    if(st==n){
        if(cnt>=3&&sum>2*maxm){
            ans++;
            ans%=mod;
        }
        return;
    }
    dfs(st+1,cnt,sum,maxm);
    maxm=max(a[st],maxm);
    sum+=a[st];
    cnt++;
    dfs(st+1,cnt,sum,maxm);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    if(a[0]==a[n-1]){
        wkq=1;
        for(int i=2;i<=n;i++){
            wkq*=i;
            wkq%=mod;
        }
        for(int i=3;i<=n;i++){
            wdl=1;
            for(int j=2;j<=i;j++){
                wdl*=j;
                wdl%=mod;
            }
            wyj=1;
            for(int j=2;j<=(n-i);j++){
                wyj*=j;
                wyj%=mod;
            }
            wgm=(wkq/((wdl*wyj)%mod))%mod;
            ans+=wgm;
            ans%=mod;
        }
        printf("%lld",ans);
        return 0;
    }
    dfs(0,0,0,-inf);
    printf("%lld",ans);
    return 0;
}
