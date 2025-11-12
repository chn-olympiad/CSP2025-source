#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,m,ans;
int a[N],sum[N],dp[N],t[N*4],h[N*6];
struct node{int l,r;}b[N];
bool cmp(node x,node y){return x.r<y.r;}
void up(int i){t[i]=max(t[i<<1],t[i<<1|1]);}
int ask(int i,int l,int r,int jobl,int jobr){
    if(jobl<=l && r<=jobr){
        return t[i];
    }
    int mid=(l+r)>>1,res=0;
    if(jobl<=mid) res=max(res,ask(i<<1,l,mid,jobl,jobr));
    if(jobr>mid) res=max(res,ask(i<<1|1,mid+1,r,jobl,jobr));
    return res;
}
void add(int i,int l,int r,int jobi,int jobv){
    if(l==r){
        t[i]+=jobv;
        return ;
    }
    int mid=(l+r)>>1;
    if(jobi<=mid) add(i<<1,l,mid,jobi,jobv);
    else add(i<<1|1,mid+1,r,jobi,jobv);
    up(i);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]^a[i]);
    }
    h[0]=0;
    for(int i=1;i<=(1<<21)+100;i++) h[i]=-1;
    for(int i=1;i<=n;i++){
        int get=(sum[i]^k);
        if(h[get]>=0){
            m++;
            b[m].l=h[get]+1,b[m].r=i;
        }
        h[sum[i]]=i;
    }
    sort(b+1,b+1+m,cmp);
    for(int i=1;i<=m;i++){
        int get=0;
        if(b[i].l>1) get=ask(1,1,n,1,b[i].l-1);
        dp[b[i].r]=get+1;
        add(1,1,n,b[i].r,dp[b[i].r]);
        ans=max(ans,dp[b[i].r]);
    }
    cout<<ans<<'\n';
    return 0;
}
