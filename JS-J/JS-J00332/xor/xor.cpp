#include<bits/stdc++.h>
using namespace std;
struct abc {
    int num;
    bool used = false;
} a[500001];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, cnt = 0;
    cin >> n >> k;
    int res = -1, pos = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].num;
        if ((a[i].num == k) && a[i].used == false) {
            cnt++;
            res = -1;
            pos = 0;
            a[i].used = true;
            continue;
        }
        else if (res == -1 && a[i].used == false) {
            pos = i;
            res = a[i].num;
        }
        else if (res != -1 && a[i].used == false) {
            res ^= a[i].num;
            if (res == k) {
                for (int j = pos; j <= i; j++) {
                    a[j].used = true;
                }
                cnt++;
                res = -1;
                pos = 0;
            }
        }
    }
    cout << cnt;
    return 0;
}
