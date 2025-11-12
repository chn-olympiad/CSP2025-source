#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5005],cnt;
bool f[5005],flag;
void dfs(int maxn,int sumn,int k){
    if(sumn>maxn*2) cnt++;
    cnt%=mod;
    if(k>n) return;
    for(int i=k;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            dfs(max(maxn,a[i]),sumn+a[i],i);
            f[i]=0;
        }
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            flag=1;
            break;
        }
    }
    if(flag==0){
        int ans=0;
        for(int i=3;i<=n;i++){
            int l=1;
            for(int j=1;j<=i;j++){
                l*=j;
                l%=mod;
            }
            int sum=1;
            for(int j=n-i+1;j<=n;j++){
                sum*=j;
                sum%=mod;
            }
            ans+=sum/l;
            ans%=mod;
        }
        printf("%lld",ans%mod);
        return 0;
    }
    dfs(0,0,1);
    printf("%lld",cnt%mod);
    return 0;
}
