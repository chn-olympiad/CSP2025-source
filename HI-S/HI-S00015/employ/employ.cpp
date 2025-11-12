#include<bits/stdc++.h>
#define afor(i,x,y) for(int i=(x);i<=(y);i++)
#define bfor(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
typedef long long ll;
const int N=510;
const int mod=998244353;
int n,m,c[N];
char s[N];
namespace solve1{
    int main() {
        int fl=1;
        afor(i,1,n) if(s[i]=='0') fl=0;
        afor(i,1,n) if(!c[i]) fl=0;
        if(!fl) return printf("0"),0;
        int ans=1;
        afor(i,1,n) ans=1ll*ans*i%mod;
        printf("%d",ans);
        return 0;
    }
}
namespace solve2{
    int fac[N],cnt[N],ans;
    int main() {
        fac[0]=1;
        afor(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
        afor(i,1,n) cnt[c[i]]++;
        bfor(i,n,1) cnt[i]+=cnt[i+1];
        int now=1;
        afor(i,1,n) {
            if(s[i]=='0') {continue;}
            if(s[i]=='1') ans=(ans+1ll*now*cnt[i]%mod*fac[n-i]%mod)%mod;
            if(n-cnt[i]<i) break;
            now=1ll*now*(n-cnt[i]-i+1)%mod;
        }
        printf("%d",ans);
        return 0;
    }
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);
    afor(i,1,n) scanf("%d",&c[i]);
    if(m==n) return solve1::main();
    if(m==1) return solve2::main();
	return 0;
}