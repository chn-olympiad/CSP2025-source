#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int M=1e3+10;
int dp[M][M];
int n,m;
int a[N],sum[N];
// #define pair<int,int> pi
// #define ret return
// #define lson(p) (p<<1)
// #define rson(p) (lson(p)|1)
// pi mk(int x,int y) {return make_pair(x,y);}
// int e[N];
// void pushdown(int p){e[p]=e[lson(p)]^e[rson(p)];}
// void build(int l,int r,int p)
// {
//     if(l==r) 
//     {
//         e[p]=sum[l]; ret;
//     }
//     int mid=(l+r)>>1;
//     build(l,mid,lson(p));
//     build(mid+1,r,rson(p));
//     pushdown(p);
//     ret ;
// }
// void update(int L,int R,int l,int r,int val,int p)
// {
//     if(l<=L and r>=R)
//     {
//         e[p]^=sum[l];
//         ret ;
//     }
//     int mid=(L+R)>>1;
//     if(L<=mid) update(L,mid,l,r,val,lson(p));
//     if(R>mid) update(mid+1,R,l,r,val,rson(p));
//     pushdown(p);ret ;
// }
// int query(int L,int R,int l,int r,int p)
// {
//     if(l<=L and r>=R)
//     {
//         e[p]^=sum[l];
//         ret ;
//     }
//     int mid=(L+R)>>1;int ans=0;
//     if(L<=mid) ans^=query(L,mid,l,r,lson(p));
//     if(R>mid) ans^=query(mid+1,R,l,r,rson(p));
//     pushdown(p);ret ans;
// }
// int query_range(int l,int r)
// {
//     int ansl= query(1,n,1,l,1);
//     int ansr=query(1,n,1,r,1);
//     ret ansr^ansl;
// }
int maxx[N];
void init()
{
    if(a[1]==m) dp[1][1]=1;
    else dp[1][1]=0;
    maxx[1]=dp[1][1];
    return ;
}
int query(int l,int r)
{
    return (sum[r]^sum[l-1]);
}
int cnt=0;int tmp;int ans;

void solve()
{
    for(int i=1;i<=n;i++) maxx[i]=INT_MIN;
    init();
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(query(j,i)==m) dp[i][j]=maxx[j-1]+1;
            else dp[i][j]=maxx[j-1];
            maxx[i]=max(maxx[i],dp[i][j]);
            ans=max(ans,maxx[i]);
        }
    }
    return ;
}
void solve2()
{
    if(m==0)
    {
        int len=1;
        bool f=true;int cnt_size=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                f=true;
                if(!(len%2)) ans++;
                ans++;
            }
            else
            {
                if(f)
                {
                    len=1;
                    f=false;
                }
                else len++;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) ans++;
        }
    }
    return ;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];if(a[i]==1) cnt++;
        if(a[i]==0 or a[i]==1) tmp++;
        // if(a[i]==m) ans++;
        sum[i]=sum[i-1]^a[i];
    }
    if(cnt==n and m==0) {cout<<n<<'\n';return 0;}
    else if(tmp==n) solve2();
    else solve();
    cout<<ans<<'\n';
}