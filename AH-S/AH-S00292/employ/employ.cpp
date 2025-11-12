#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

#define fi first
#define se second
#define pb push_back

const ll Md=998244353;

int n,m;
char str[505]; int a[505],c[505],s[505],kk[505];
ll com[505][505],fac[505];

void upd(ll &x,ll y) {x=(x+y)%Md;}

namespace bf {
    ll dp[(1<<18)+5][19];
    
    void solve() {
        dp[0][0]=1;
        for(int msk=0;msk<(1<<n)-1;++msk) {
            int o=__builtin_popcount(msk);
            for(int i=1;i<=n;++i) if(!((msk>>(i-1))&1)) {
                for(int j=0;j<=o;++j) if(a[o+1] && kk[i]>o-j) upd(dp[msk|(1<<(i-1))][j+1],dp[msk][j]); 
                                      else upd(dp[msk|(1<<(i-1))][j],dp[msk][j]);
            }
        }
        ll ans=0;
        for(int i=m;i<=n;++i) upd(ans,dp[(1<<n)-1][i]); cout << ans << "\n";
    }
};

namespace A {
    ll dp[2][505][505];

    void solve() {
        dp[0][0][0]=1;
        for(int i=0,d=1;i<n;++i,d=d^1) {
            memset(dp[d],0,sizeof dp[d]);
            for(int j=0;j<=i && j<=n-m;++j) for(int k=0;k<=i-j;++k) {
                if(s[n]-s[j]<i-j-k) {dp[d][j][k]=0; continue;}
                // succ
                upd(dp[d][j][k],dp[d^1][j][k]);
                // fail
                for(int h=0;h<=c[j+1] && k+h<=i-j;++h) upd(dp[d][j+1][k+h],dp[d^1][j][k]*com[h][c[j+1]]%Md*com[h][i-j-k]%Md*fac[h]%Md*(s[j]-k-j));
            } 
        }
        ll ans=0;
        for(int i=0;i<=n-m;++i) for(int j=0;j<=n-i;++j) if(s[n]-s[i]==n-i-j) upd(ans,dp[n&1][i][j]*fac[n-i-j]);
        cout << ans << "\n";
    }
};

namespace sub1 {
    ll dp[505][505];
    
    void solve() {
        dp[0][0]=1;
        for(int i=0;i<n;++i) {
            for(int j=0;j<=i;++j) {
                if(j>s[n]-s[i]) {dp[i][j]=0; continue;}
                // c_w <= i
                for(int h=0;h<=c[i+1] && j-h>=0;++h) upd(dp[i+1][j-h],dp[i][j]*com[h][j]%Md*com[h][c[i+1]]%Md*fac[h]%Md*(s[i]-(i-j)));
                // c_w > i
                if(a[i]) continue;
                for(int o=0;o<=1 && o<=c[i+1];++o) for(int h=0;h+o<=c[i+1] && j-h>=0;++h) upd(dp[i+1][j-h+1-o],dp[i][j]*com[h][j]%Md*(o?c[i+1]:1)%Md*com[h][c[i+1]-o]%Md*fac[h]);
            }
        }
        ll ans=(fac[n]-dp[n][0]+Md)%Md; cout << ans << "\n";
    }
};

void wk() {
    cin >> n >> m >> str+1;
    com[0][0]=1; 
    for(int i=1;i<=n;++i) {
        com[0][i]=1;
        for(int j=1;j<=i;++j) com[j][i]=(com[j-1][i-1]+com[j][i-1])%Md;
    }
    fac[0]=1; for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%Md;
    for(int i=1;i<=n;++i) a[i]=str[i]-'0';
    for(int i=1,x;i<=n;++i) {
        cin >> x; ++c[x]; kk[i]=x;
    } s[0]=c[0];
    for(int i=1;i<=n;++i) s[i]=s[i-1]+c[i];
    if(n<=18) {bf::solve(); return ;}
    if(*min_element(a+1,a+n+1)) {A::solve(); return ;}
    if(m==n && !(*min_element(a+1,a+n+1))) {cout << "0\n"; return ;}
    if(m==n) {A::solve(); return ;}
    if(m==1) {sub1::solve(); return ;}
}

signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    ios::sync_with_stdio(false);

    wk();

    return 0;
}

// Make asdfz great again!
/*
password:
Ren5Jie4Di4Ling5%
*/