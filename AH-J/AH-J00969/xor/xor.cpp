#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
struct Node{
    LL l,r;
    bool operator <(const Node &rhs) const{
        return r<rhs.r;
    }
}s[N];
LL n,k,a[N],sum[N],m,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++) if(a[i]==k)
    for(LL i=1;i<=n;i++){
        for(LL j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                s[++m].l=i,s[m].r=j;
            }
        }
    }
    sort(s+1,s+m+1);
    LL pre=0;
    for(int i=1;i<=m;i++){
        while(s[i].l<=pre&&i<=m) i++;
        if(s[i].l>pre&&i<=m){
            ans++;
            pre=max(s[i].r,pre);
        }
    }
    cout<<ans<<" "<<n;
    return 0;
}
