#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500010],sum[500010];
vector<LL> v[2000000];
struct str{
    LL l,r;
}b[500010];
bool cmp(const str &x,const str &y){
    return x.r!=y.r?x.r<y.r:x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    LL n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]^a[i];
        v[sum[i]].push_back(i);
    }
    LL t=0;
    for(int i=1;i<=n;i++){
        while(!v[LL(sum[i-1]^k)].empty()&&v[LL(sum[i-1]^k)].front()<i){
            v[LL(sum[i-1]^k)].erase(v[LL(sum[i-1]^k)].begin());
        }
        for(int j=0;j<v[sum[i-1]^k].size();j++){
            if(v[sum[i-1]^k][j]<i){
                v[sum[i-1]^k].erase(v[sum[i-1]^k].begin()+j);
                j--;
                continue;
            }
            t++;
            b[t].l=i;
            b[t].r=v[sum[i-1]^k][j];
            break;
        }
    }
    sort(b+1,b+t+1,cmp);
    LL ans=1;
    LL R=b[1].r;
    for(int i=2;i<=t;i++){
        if(b[i].l>R){
            ans++;
            R=b[i].r;
        }
    }
    printf("%lld",ans);
    return 0;
}
