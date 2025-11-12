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
    while (ch<'0' or ch>'9') {if (ch=='-')  f=-f;ch=getchar();}
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
int n,m,a[1005],ans,b[105][105];
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    n=read(),m=read();
    for (int i=1;i<=n*m;i++)
        a[i]=read();
    ans=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=1,x=1,y=1,op=1;
    while (cnt<=n*m){
        b[x][y]=a[cnt++];
        x+=op;
        if (x==n+1)
            x=n,y++,op=-op;
        else if (x==0)
            x=1,y++,op=-op;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (b[i][j]==ans){
                printf("%d %d\n",j,i);
                return;
            }
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll t=1;
    // t=read();
    while (t--)
        solve();
    return 0;
}