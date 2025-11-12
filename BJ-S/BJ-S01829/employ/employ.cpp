#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,s[510],c[510],p[510],ans,fac[510];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%1lld",&s[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
        p[i]=i;
    }
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            //printf("p%lld ",p[i]);
            if(s[i]==0||cnt>=c[p[i]]){
                cnt++;
            }
        }
        //printf("\n");
        //printf("%lld\n",n-cnt);
        ans+=((n-cnt)>=m);
    }while(next_permutation(p+1,p+n+1));
    printf("%lld\n",ans);
    return 0;
}
