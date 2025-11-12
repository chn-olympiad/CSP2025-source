#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
const int N = 5e5 + 10;
int n,k,ans;
int seg[N<<2];
int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
void push_up(int x){seg[x]=seg[ls(x)]^seg[rs(x)];}
void build(int x,int l,int r){
    if(l==r){cin>>seg[x];return ;}
    build(ls(x),l,mid),build(rs(x),mid+1,r),push_up(x);
}
int query(int x,int l,int r,int L,int R,int res){
    if(L<=l && r<=R) return seg[x];
    if(L<=mid) res=query(ls(x),l,mid,L,R,0);
    if(mid<R) res^=query(rs(x),mid+1,r,L,R,0);
    return res;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
    cin>>n>>k;
    build(1,1,n);
    int st=1;
    for(int i=1;i<=n;++i){
        for(int j=st;j<=i;++j) if(query(1,1,n,j,i,0)==k) {ans++,st=i+1;break;}
    }
    cout<<ans;
    return 0;
}