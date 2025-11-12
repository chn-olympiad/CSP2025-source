#include <bits/stdc++.h>
using namespace std;
int a[5001];
long long ans = 0;
const long long mod = 998244353;
int n;
void dfs(int pos,int sum,int maxn,int cnt,bool f){
    if(cnt >= 3 && f){
        if(sum > 2 * maxn){
            ans = (ans + 1) % mod;
        }
    }
    if(pos > n) return;
    dfs(pos+1,sum+a[pos],max(maxn,a[pos]),cnt+1,1);
    dfs(pos+1,sum,maxn,cnt,0);
}
long long f(int k){
    long long t = 1;
    for(int i = n;i >= n - k + 1;i --) t = t * i % mod;
    for(int i = 1;i <= k;i ++) t = t / (i % mod);
   // cout << t << '\n';
    return t;
}
int main(){
   freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int w = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        w = max(a[i],w);
    }
    if(w == 1){
        int ans1 = 0;
        for(int i = 3;i <= n;i ++){
            ans1 = (ans1 + f(i) % mod) % mod;
        }
        cout << ans1;
        return 0;
    }
    dfs(1,0,0,0,0);
    cout << ans;
    return 0;
}