#include <bits/stdc++.h>;
using namespace std;
typedef long long LL;
const LL N=5e5+10;
struct node{
    LL l,r;
}a[2000010];
bool cmp(const node &x,const node &y){
    return x.r<y.r;
}
LL n,k,tot;
bool vis[N];
LL ai[N],qz[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&ai[i]);
        qz[i]=qz[i-1]^ai[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            if((qz[r]^qz[l-1])==k){
                tot++;
                a[tot].l=l;
                a[tot].r=r;
            }
        }
    }
    sort(a+1,a+tot+1,cmp);
    LL cnt=1,R=a[1].r;
    for(int i=2;i<=tot;i++){
        if(a[i].l>R) {
            R=a[i].r;
            cnt++;
        }
    }
    printf("%lld",cnt);
    return 0;
}
