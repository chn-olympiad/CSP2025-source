#include<iostream>
#include<vector>
#define long long int
using namespace std;

int a[500005], ans = 0, n = 0, k = 0;

int calc(int l, int r){
    int ans = a[l];
    for(int i = l + 1;i <= r;i ++){
        ans ^= a[i];
    }
    return ans;
}

void dfs(int& num, int l, int r){
    if(r == n + 1){
        return;
    }
    if(calc(l, r) == k){
        num ++;
    }
    for(int i = r + 1;i <= n;i ++){
        for(int j = i;j <= n;j ++){
            dfs(num, i, j);
        }
    }
}

signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    int ans = 0;
    dfs(ans, 1, 1);
    cout << ans;
    return 0;
}
