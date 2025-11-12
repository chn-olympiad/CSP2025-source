#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        if(a[i]==k)
        {
            ++cnt;
        }
    }
    printf("%lld",cnt);
    return 0;
}
