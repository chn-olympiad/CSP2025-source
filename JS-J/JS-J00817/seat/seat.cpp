#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,s=1;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&x);
    for(int i=1;i<n*m;i++){
        scanf("%lld",&y);
        if(y>x)s++;
    }
    int t=(s-1)/n+1,u=(s-1)%(2*n)+1;
    if(t&1)printf("%lld %lld",t,u);
    else printf("%lld %lld",t,2*n-u+1);
    return 0;
}
