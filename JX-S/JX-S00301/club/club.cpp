#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
#define pow po_w
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9'){ if (ch=='-')f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll po_w(ll x,ll y,ll mod){
    ll ans=1;
    while (y){
        if (y&1)
            ans*=x;
        x*=x;
        y>>=1;
        x%=mod;
        ans%=mod;
    }
    return ans;
}
ll gcd(ll x,ll y){
    if (y==0)
        return x;
    return gcd(y,x%y);
}
int n;
struct node{
    int a,b,c;
}a[100005];
int dp[205][205][205];
bool flot1,flot2,flot3;
bool cmp(node x,node y){
    return x.a>y.a;
}
void solve(){
    n=read();
    for (int i=1;i<=n;i++)
        a[i].a=read(),a[i].b=read(),a[i].c=read();
    for (int i=1;i<=n;i++){
        if (a[i].a!=0)
            flot1=true;
        if (a[i].b!=0)
            flot2=true;
        if (a[i].c!=0)
            flot3=true;
    }
    if (flot2==false and flot3==false){
        sort(a+1,a+n+1,cmp);
        ll sum=0;
        for (int i=1;i<=n/2;i++)
            sum+=a[i].a;
        printf("%lld\n",sum);
        return;
    }
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++){
        for (int j=0;j<=i;j++){
            for (int k=0;k<=i;k++){
                int w=i-j-k;
                if (w<0)
                    break;
                if (j*2<=n and j!=0)
                    dp[j][k][w]=max(dp[j][k][w],dp[j-1][k][w]+a[i].a);
                if (k*2<=n and k!=0)
                    dp[j][k][w]=max(dp[j][k][w],dp[j][k-1][w]+a[i].b);
                if (w*2<=n and w!=0)
                    dp[j][k][w]=max(dp[j][k][w],dp[j][k][w-1]+a[i].c);
            }
        }
    }
    ll ans=0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            int k=n-i-j;
            if (k<0)
                break;
            ans=max(ans,1ll*dp[i][j][k]);
            // printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t=1;
    t=read();
    while (t--)
        solve();
    return 0;
}