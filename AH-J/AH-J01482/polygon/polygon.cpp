//AH-J01482 Eason Cyj001001
#include "bits/stdc++.h"
#define int long long

using namespace std;
const int MOD = 998244353;
const int N = 5000;
int n;
bool t[10];
int a[N];
int kc[N][N];
int ans;


void dfs(int x,int maxn,int sum,int cnt) {
    if(x==n+1){
        if(cnt <= 2) return;
        if(maxn*2 >= sum) return;
        ans++;
        ans %= MOD;
        return ;
    }
    dfs(x+1,max(maxn,a[x]),sum+a[x],cnt+1);
    dfs(x+1,maxn,sum,cnt);
}

int Cnm(int n,int m) {
    if(kc[n][m]!=-1) return kc[n][m];
    if(n>m) return kc[n][m] =  0;
    if(m-n <= m) n= m-n;
    if(n==m) return kc[n][m] = 1;
    if(n==1) return kc[n][m] = m;
    if(n==0) return kc[n][m] = 1;
    kc[n][m] = (Cnm(n-1,m) % MOD + Cnm(n-1,m-1) % MOD) % MOD;
    kc[n][m] %= MOD;
    return kc[n][m];
}

signed main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    if(n<=20) {
        dfs(1,0,0,0);
        cout << ans;
    }else{
        memset(kc,-1,sizeof(kc));
        for(int i=3; i<=n; i++) {
            ans += Cnm(i,n) % MOD;
            ans %= MOD;
        }
        cout << ans;
    }
    return 0;
}
