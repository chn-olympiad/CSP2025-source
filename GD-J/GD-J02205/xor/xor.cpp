#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000005;
ll a[N],d[N],n,k,m=1,ans;
void build(int s,int t,int p){
    if(s==t){
        d[p]=a[s];
        return;
    }
    ll mid=s+((t-s)>>1);
    build(s,mid,2*p),build(mid+1,t,2*p+1);
    d[p]=d[2*p]^d[2*p+1];
}
int query(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r)return d[p];
    ll mid=s+((t-s)>>1),ans=0;
    if(l<=mid)ans=query(l,r,s,mid,2*p);
    if(r>mid)ans^=query(l,r,mid+1,t,2*p+1);
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;++i)cin>>a[i];
    build(1,n,1);
    for(ll i=1;i<=n;++i){
        for(ll j=m;j<=i;++j){
            if(query(j,i,1,n,1)==k){
                ++ans;
                m=i+1;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
