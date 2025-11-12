#include <cstdio>
#include <algorithm>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
char s[200005];
int c[200005];
int jc[200005];
int d[200005];
//int jcny[200005];
/*inline int ksm(int a,int b){
    int ans=0;
    while(b!=0){
        if(b&1){
            ans=1ll*ans*a%mod;
        }
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}*/
int p[200005];
int flgs;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        if(c[i]!=0){
            flgs++;
        }
    }
    bool flagA=true;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            flagA=false;
            break;
        }
    }
    if(flagA){
        jc[0]=1;
        for(int i=1;i<=n;i++){
            jc[i]=1ll*jc[i-1]*i%mod;
        }
        /*jcny[n]=ksm(jc[n],mod-2);
        for(int i=n-1;i>=0;i--){
            jcny[i]=1ll*jcny[i+1]*(i+1)%mod;
        }*/
        printf("%lld\n",1ll*jc[flgs]);
        return 0;
    }
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    ll ans=0;
    do{
        int fans=0;
        d[0]=0;
        for(int i=1;i<=n;i++){
            d[i]=d[i-1];
            if(d[i-1]<c[p[i]] && s[i]=='1'){
                fans++;
            }
            else{
                d[i]++;
            }
        }
        if(fans>=m){
            ans++;
            ans%=mod;
        }
    }while(next_permutation(p+1,p+n+1));
    printf("%lld\n",ans);
    return 0;
}