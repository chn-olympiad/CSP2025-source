#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int mod = 998244353;
int n, cnt;
int a[maxn];
void dfs(int i, int maxx, int sum, int m){
    if(i > n){
        if(maxx * 2 < sum && m >= 3){
            cnt++;
            cnt %= mod;
        }return ;
    }
    dfs(i + 1, maxx, sum, m);
    dfs(i + 1, max(maxx, a[i]), sum + a[i], m + 1);
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1, 0, 0, 0);
    cout << cnt;
    return 0;
}
