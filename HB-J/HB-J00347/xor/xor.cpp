#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,k;
int a[N],s[N];
int book[N];
int w[N*4],lzy[N*4];
inline bool InRange(int L,int R,int l,int r) {
    return (l<=L) && (R<=r);
}
inline bool OutOfRange(int L,int R,int l,int r) {
    return (R<l) || (L>r);
}
void maketag(const int u,int len,int x) {
    w[u]+=len*x;
    lzy[u]+=x;
}
void pushdown(const int u,int L,int R) {
    int mid=(L+R)>>1;
    maketag(u*2,mid-L+1,lzy[u]);
    maketag(u*2+1,R-mid,lzy[u]);
    lzy[u]=0;
}
void pushup(const int u) {
    w[u]=w[u*2]+w[u*2+1];
}
void update(const int u,int L,int R,int l,int r) {
    if(InRange(L,R,l,r)) maketag(u,R-L+1,1);
    else if(!OutOfRange(L,R,l,r)) {
        pushdown(u,L,R);
        int mid=(L+R)>>1;
        update(u*2,L,mid,l,r);
        update(u*2+1,mid+1,R,l,r);
        pushup(u);
    }
}
int query(const int u,int L,int R,int l,int r) {
    if(InRange(L,R,l,r)) return w[u];
    else if(!OutOfRange(L,R,l,r)) {
        int mid=(L+R)>>1;
        pushdown(u,L,R);
        return query(u*2,L,mid,l,r)+query(u*2+1,mid+1,R,l,r);
    } else return 0;
}
signed main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            int w=s[i]^s[j-1];
            if(w==k && !(query(1,1,n,j,i) >= 1)) {
                ans++;
                update(1,1,n,j,i);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}