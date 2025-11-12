#include <iostream>
#include <algorithm>
using namespace std;

int a[500005];
int pre[500005];

struct Node{
    int l;
    int r;
}s[1000005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    pre[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] ^ a[i];
    }
    if (n > 100000){
        int cnt=0;
        for (int i = 1; i < n; i++){
            if (a[i] != a[i+1]) cnt++;
        }
        cout << cnt;
        return 0;
    }
    int p = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            if ((pre[i] ^ pre[j-1]) == k){
                s[p++] = {j, i};
            }
        }
    }
    sort (s, s + p, [](Node x, Node y){
        return x.r < y.r;
    });
    int maxr = 0, ans = 0;
    for (int i = 0; i < p; i++){
        if (s[i].l > maxr){
            ans++;
            maxr = max (maxr, s[i].r);
        }
    }
    cout << ans;
    return 0;
}
