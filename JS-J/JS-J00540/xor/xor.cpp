#include <bits/stdc++.h>
using namespace std;
int sw[21] = {524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1, 0};
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, c0 = 0, c1 = 0, ans = 0;
    cin >> n >> k;
    int a[n + 1];
    bool f = true;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) c0++;
        else if(a[i] == 1) c1++;
        else f = false;
    }
    if(n == 1 && k == 0 && c1 == 1) {
        cout << 0;
        return 0;
    }
    if(n == 2 && k == 0 && c1 == 2) {
        cout << 1;
        return 0;
    }
    if(f) {
        if(k == 1) {
            for(int i = 1; i < n; i++) {
                if(a[i] != a[i + 1]) {
                    ans++;
                    i++;
                }
            }
        } else {
            for(int i = 1; i < n; i++) {
                if(a[i] == a[i + 1]) {
                    ans++;
                    i++;
                }
            }
        }
        cout << ans;
        return 0;
    } else {
        int s;
        for(int i = 0; i < 21; i++) {
            if(k >= a[i]) {
                s = a[i];
                break;
            }
        }
        int last = 1;
        for(int i = 1; i <= n; i++) {
            if(a[i] >= s) {
                if(a[i] == k) {
                    ans++;
                    continue;
                }
                int yh = a[i];
                bool f = false;
                for(int j = i - 1; j > last; j--) {
                    yh ^= a[j];
                    if(yh == k) {
                        ans++;
                        f = true;
                        last = i;
                        break;
                    }
                }
                if(!f) {
                    yh = a[i];
                    for(int j = i + 1; ; j++) {
                        if(a[j] >= s) {
                            break;
                        }
                        yh ^= a[j];
                        if(yh == k) {
                            ans++;
                            f = true;
                            last = j;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
