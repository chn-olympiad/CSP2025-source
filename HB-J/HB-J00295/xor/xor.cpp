#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],pre[N];
struct node{
    int l,r;
}g[N*10];
bool cmp(node x,node y){
    if(x.r==y.r) return x.l<y.l;
    else return x.r<y.r;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k; int cnt=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i==1) pre[i]=a[i];
        else pre[i]=pre[i-1]^a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            int val=pre[j]^pre[i-1];
            if(val==k) g[++cnt].l=i,g[cnt].r=j;
        }
    }
    sort(g+1,g+1+cnt,cmp); int ans=0,cur=0;
    for(int i=1;i<=cnt;++i){
        // cout<<g[i].l<<" "<<g[i].r<<'\n';
        if(g[i].l<=cur) continue;
        else ++ans,cur=g[i].r;
    }
    cout<<ans; return 0;
}