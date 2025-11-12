#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 5010;
int n, k, a[N], dp[300], tmp[300];
struct node {
    int l, r;
};
vector<node> v;
bool cmp(node x, node y) {
    return x.r < y.r;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0;i < n;i ++) {
        cin >> a[i];
    }
    if(n <= 5000) {
        for(int i = 0;i < n;i ++) {
            int tmp = 0;
            for(int j = i;j < n;j ++) {
                tmp = (tmp ^ a[j]);
                if(tmp == k) {
                    v.push_back({i, j});
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        int R = -1, ans = 0;
        for(int i = 0;i < v.size();i ++) {
            if(v[i].l > R) {
                ans ++;
                R = v[i].r;
            }
        }
        cout << ans;
    }else {
        int ans = 0;
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < 280;j ++) {
                if(dp[j] == 1){
                    tmp[(j ^ a[i])] = 1;
                }
            }
            tmp[a[i]] = 1;
            for(int j = 0;j < 280;j ++) {
                dp[j] = tmp[j];
            }
            if(dp[k] == 1) {
                ans ++;
                for(int j = 0;j < 280;j ++) {
                    dp[j] = 0;
                }
            }
            for(int j = 0;j < 280;j ++) {
                tmp[j] = 0;
            }
        }
        cout << ans;
    }
    return 0;
}
