#include <bits/stdc++.h>
#define P 998244353
using namespace std;

int n, ans, tmp;
vector<int> v;

void dfs(int p, int t, int sum, int mx, int num){
    if(t==1){
        if(mx>0 && num>=3 && sum>2*mx) ans++;
        ans%=P;
    }
    if(p==n) return;
    dfs(p+1, 1, sum+v[p+1], max(mx, v[p+1]), num+1);
    dfs(p+1, 0, sum, mx, num);
}

int dp[5005][5005];

void f(){
    for(int i=1; i<5005; i++) dp[i][1]=dp[i][i]=1;
    for(int i=2; i<5005; i++){
        for(int j=2; j<=i; j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%P;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    v.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
        tmp=max(tmp, v[i]);
    } 
    if(tmp==1){
        for(int i=3; i<=n; i++){
            ans+=dp[n][i];
            ans%=P;
        }
    }
    dfs(0, 0, 0, 0, 0);
    cout << ans%P;
    return 0;
}
