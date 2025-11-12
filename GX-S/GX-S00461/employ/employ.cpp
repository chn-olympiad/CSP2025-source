#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,m;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
        ans=(ans*i)%MOD;
    printf("%lld",ans);
    return 0;
}
