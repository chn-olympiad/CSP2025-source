#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 998244353;
int a[maxn];
int n;
long long ans = 0;

int jud(){
    for(int i=1;i<=n;i++){
        if(a[i] != 1) return 0;
    }
    return 1;
}

long long c(int u, int d){
    if(u > (d / 2)) u = d - u;
    long long un = 1, dn = 1;
    for(int i=1;i<=u;i++) un *= (d - i + 1);
    for(int i=1;i<=u;i++) dn *= i;
    return un / dn;
}

void con(){
    for(int l=3;l<=n;l++){
        ans += c(l, n);
        ans %= mod;
    }
}

void dfs(int pos, long long tot, int cnt){
    if(pos > n) return ;
    tot += a[pos];
    int num = cnt;
    cnt = max(cnt, a[pos]);
    if(tot > 2 * cnt) ans ++;
    ans %= mod;
    dfs(pos+1, tot, cnt);
    cnt = num;
    tot -= a[pos];
    dfs(pos+1, tot, cnt);
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    if(jud()){
        con();
        cout<<ans;
        return 0;
    }
    dfs(1, 0, 0);
    cout<<ans;

    return 0;
}
