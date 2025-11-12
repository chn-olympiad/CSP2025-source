#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int st,en;
}b[500005];
bool cmp(node x,node y){
    return x.en<y.en;
}
int n,k,a[500005],xs[500005],sum;
set<int>s[1<<21];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        xs[i]=xs[i-1]^a[i];
        s[xs[i]].insert(i);
    }
    for(int i=1;i<=n;i++){
        int tgt=k^xs[i-1];
        auto r=s[tgt].lower_bound(i);
        if((*r)>=i)b[++sum]={i,(*r)};
    }
    sort(b+1,b+sum+1,cmp);
    int now=0,ans=0;
    for(int i=1;i<=sum;i++){
        if(b[i].st>now){
            ans++;
            now=b[i].en;
        }
    }
    printf("%lld",ans);
    return 0;
}
