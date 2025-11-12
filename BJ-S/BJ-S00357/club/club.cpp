#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
template<typename T>
inline void read(T &x){
    bool f=0;
    x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    x=f?-x:x;
}
template<typename T>
void write(T x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1e5+5;
int n;
struct node{
    int a,b,c;
}a[N],b[N];
int dp[205][205][205],v[N],d[N];
inline bool cmp1(node a,node b){
    if(a.a-a.b!=b.a-b.b) return a.a-a.b>b.a-b.b;
    return a.b-a.c>b.b-b.c;
}
inline bool cmp(node a,node b){
    return a.a>b.a;
}
inline void solve(){
    read(n);
    rep(i,1,n) read(a[i].a),read(a[i].b),read(a[i].c),v[i]=d[i]=0;
    if(n<=200){
        memset(dp,0,sizeof(dp));
        rep(i,1,n){
            rep(j,0,i){
                rep(k,0,i-j){
                    if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].a);
                    if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].b);
                    if(i-j-k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].c);
                }
            }
        }
        int ans=0,ai=0,aj=0;
        rep(i,0,n/2){
            rep(j,0,n/2){
                if(i+j<n/2) continue;
                if(dp[n][i][j]>ans) ai=i,aj=j;
                ans=max(ans,dp[n][i][j]);
            }
        }
        write(ans),putchar('\n');
    }else{
        int ans=0;
        sort(a+1,a+n+1,cmp1);
        rep(i,1,n){
            if(i<=n/2) v[i]=a[i].a;
            else v[i]=a[i].b;
            ans+=v[i];
            d[i]=a[i].c-v[i];
        }
        sort(d+1,d+n+1,greater<int>());
        rep(i,1,n/2) ans+=max(0ll,d[i]);
        write(ans),putchar('\n');
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;read(T);
    while(T--) solve();
    return 0;
}
/*
6
1 2 3
1 2 3
3 2 1
3 2 1
3 1 2
3 1 2
*/