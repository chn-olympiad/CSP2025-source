#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],qzh[500005],b1,ans,qq;
struct dui{
    long long l,r;
}b[1000005];
long long check(long long A,long long B){
    return qzh[B]^qzh[A-1];
}
bool cmp(dui A,dui B){
    if(A.r!=B.r)return A.r<B.r;
    return A.l>B.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    qzh[1]=a[1];
    for(long long i=2;i<=n;i++)qzh[i]=qzh[i-1]^a[i];
    for(long long i=1;i<=n;i++)
        for(long long j=i;j<=n;j++)
            if(k==check(i,j)){
                b[++b1].l=i;
                b[b1].r=j;
            }
    sort(b+1,b+b1+1,cmp);
    for(long long i=1;i<=b1;i++){
        if(b[i].l>=qq){
            ans++;
            qq=b[i].r+1;
        }
    }
    cout<<ans;
    cout<<'\n';
    return 0;
}
