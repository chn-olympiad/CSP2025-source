#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 9;
unordered_map<int, int>buc;
int sum[N];
int n, k, ans;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x;   cin >> x;
        sum[i] = sum[i - 1] ^ x;
    }

    buc[0] = 1;
    int lst = -1;
    for(int i = 1; i <= n; i++){
        int x = k ^ sum[i];
        int l = !buc[x] ? -1 : buc[x];
        buc[sum[i]] = i + 1;
        if(l == -1) continue;
        if(l <= lst) continue;
        //cout << x << ' ' << sum[i] << ' ' << l << ' ' << i << '\n';
        ans++; lst = i;
    }
    cout << ans << '\n';
    return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/