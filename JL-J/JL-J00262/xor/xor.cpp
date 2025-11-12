#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k;\
ll cnt;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll x=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        x^=ll(a[i]);
        if(x==ll(k))
            cnt++,x=ll(0);
        if(x>k)
            x=ll(0);
    }
    printf("%lld",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
