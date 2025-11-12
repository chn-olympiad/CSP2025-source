#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e7+3;
struct node{
    int l,r;
}x[maxn];
bool cmp(node x,node y)
{
    return x.r<y.r;
}
int n,k,t,r,cnt,ans=1,a[maxn],pre[maxn];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==1) pre[i]=a[i];
        else pre[i]=pre[i-1]^a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            t=(pre[i]^pre[j-1]);
            if(t==k){
                x[cnt].l=j;
                x[cnt].r=i;
                cnt++;
            }
        }
    }
    sort(x,x+cnt,cmp);
    r=x[0].r;
    for(int i=1;i<cnt;i++){
        if(x[i].l>r){
            r=x[i].r;
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
