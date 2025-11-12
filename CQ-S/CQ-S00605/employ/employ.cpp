#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int p[503],n,m,i,j,c[503],l,ans;
string s;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(i=1;i<=n;i++) p[i]=i;
    if(n<=10){
        do{
            j=l=0;
            for(i=1;i<=n;i++){
                if(s[i-1]=='0'||j>=c[p[i]]) j++;
                else l++;
            }
            if(l>=m) ans++;
        }while(next_permutation(p+1,p+1+n));
        printf("%lld",ans%mod);
        return 0;
    }
    ans=1;
    for(i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    printf("%lld",ans);
}