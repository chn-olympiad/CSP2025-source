#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500009],b[5000009],ans,cnt;
struct node{
    long long l,r;
}qujian[1000009];
bool cmp(node x,node y){
    if(x.r==y.r)return x.l<y.l;
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            long long tmp=b[j]^b[i-1];
            if(tmp==k){
                qujian[++cnt].l=i;
                qujian[cnt].r=j;
            }
        }
    }
    sort(qujian+1,qujian+1+cnt,cmp);
    long long p=0;
    for(int i=1;i<=cnt;i++){
        if(p<qujian[i].l){
            ans++;
            p=qujian[i].r;
        }
    }
    printf("%lld",ans);
    return 0;
}
