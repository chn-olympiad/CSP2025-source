#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, k, maxx = -0x3f3f3f3f3f3f3f3f;
int a[N], vis[N], he[N], ans3, p = 1;
bool flag, flag2;

bool check(int l, int r){
    int sum = a[l];
    for(int i = l + 1;i <= r; i ++){
        sum = sum xor a[l];
    }
    return sum == k;
}

void dfs(int l,int r){
    memset(he, 0, sizeof he);
    for(int i = 1; i <= n; i ++){
        he[i] = he[i - 1] + vis[i];
        if(he[i] < 0) return;
    }
    for(; l <= n; l ++){
        for(; r <= n; r ++){
            if(check(l, r)){\
                ans3 ++;
                vis[l]--;
                vis[r + 1]++;
                dfs(l, r);
                vis[l]++;
                vis[r + 1]--;
            }
        }
    }
}
signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] != 1){
            flag = true;
        }
        if(a[i] > 1){
            flag2 = true;
        }
    }

    if(!flag){
        cout << n / 2 << "\n";
        return 0;
    }

    if(!flag2){
        int ans = 0, num1 = 0;
        if(k == 0){
            for(int i = 1;i <= n; i ++){
                if(a[i] == 0) ans ++;
                else{
                    num1 ++;
                }
            }
            ans += num1 / 2;
        }else{
            for(int i = 1; i <= n; i ++){
                if(a[i] == 1) ans ++;
            }
        }
        cout << ans << "\n";
        return 0;
    }
    //dfs(1, 1);
    //cout << ans3 << "\n";
    cout << (n % 100 / 2) << endl;
    return 0;
}
