#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int n, k, ans;
int a[MAXN], pre[MAXN];
int flag[MAXN];

void dfs(int i, int cnt){
    if (i > n){
        ans = max(ans, cnt);
        return;
    }
    if(flag[i] >= cnt && flag[i]){
        return;
    }
    if (cnt + n - i + 1 < ans) return;
    flag[i] = cnt;
    int target = pre[i - 1] ^ k;
    for(int j = i; j <= n; j++){
        if (pre[j] == target){
            dfs(j + 1, cnt + 1);  // choose
            break;
        }
    }
    dfs(i + 1, cnt);  // not choose
}

int main(){
    // Only 1-12
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
