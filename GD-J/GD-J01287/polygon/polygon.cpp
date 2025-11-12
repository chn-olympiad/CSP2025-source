#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 5;
const int MOD = 998244353;

int N;
int arr[MAXN];
int ps[MAXN] = {0};
int Min = 2e9;

int dfs(int idx,int Max,int sum,int len) {
    if (Max < sum + Min) {
        return 1;
    }
    if (idx == N) {
        return 1;
    }
    int ret = 0;
    if (Max >= sum + arr[idx+1] || len < 2) {
        ret += dfs(idx+1,max(Max,arr[idx+1]),sum+arr[idx+1],len+1);
        ret %= MOD;
    }
    ret += dfs(idx+1,Max,sum,len);
    ret %= MOD;
    return ret;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        Min = min(Min,arr[i]);
    }
    if (N == 3) {
        if (max(arr[1],max(arr[2],arr[3])) * 2 < arr[1] + arr[2] + arr[3]) cout << 1;
        else cout << 0;
        return 0;
    } else if (N < 3) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    for(int i=1; i<=N; i++) {
        int tmp = 1;
        for(int j=N-i+1; j<=N; j++) {
            tmp = tmp * j % MOD;
        }
        for(int j=1; j<=i; j++) {
            tmp /= j;
        }
        ans = (ans + tmp) % MOD;
    }
    cout << ans << "\n";
    ans -= dfs(1,arr[1],arr[1],1);
    ans -= dfs(1,0,0,0);
    cout << ans;

    return 0;
}