#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+5;
LL T,n;
struct Node{
    LL w[5]={0};
}x[N];
bool cmp1(const Node &x,const Node &y){
    return x.w[1]>y.w[1];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        LL ans=0;
        scanf("%lld",&n);
        for(LL i=1;i<=n;i++)
            scanf("%lld %lld %lld",&x[i].w[1],&x[i].w[2],&x[i].w[3]);
        sort(x+1,x+n+1,cmp1);
        for(LL i=1;i<=n/2;i++) ans+=x[i].w[1];
        printf("%lld",ans);
    }
    return 0;
}
