#include<bits/stdc++.h>
using namespace std;
// /xia LuoFeng_Nanami
const int N=5e5+5,N20=1<<20;
int a[N],cnt[20],p[N],id[N],sum[N20];
inline int add(int x){
    int ret=0;
    for (int i=0;i<20;i++){
        if (x&(1<<i)) cnt[i]++;
        if (cnt[i]&1) ret|=(1<<i);
    }
    return ret;
}
inline bool cmp(int x,int y){
    return p[x]>p[y];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(sum,0x3f,sizeof(sum));
    int n,k,ans=0;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i],id[i]=i;
    sum[0]=0;
    for (int i=1;i<=n;i++){
        int x=add(a[i]);
        p[i]=sum[x^k]+1;
        sum[x]=i;
    }
    sort(id+1,id+n+1,cmp);
    int lst=1e9;
    for (int i=1;i<=n;i++){
        int y=id[i],x=p[y];
        if (x>1e9) continue;
        if (y<lst) ans++,lst=x;
    }
    cout<<ans;
    return 0;
}