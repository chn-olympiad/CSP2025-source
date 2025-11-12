#include <bits/stdc++.h>
using namespace std;

void us(bool *used, int a, int j) {
    for(int i = a; i <= j; i++) {
        used[i] = true;
    }
}

int bin(int n) {
    int c = 0;
    for(int i = 0; i < n; i++) {
        c = (c<<1) + 1;
    }
    return c;
}

int Xor(int a, int b) {
    int op = 0;
    int maxN = max(a, b);
    for(int i = 16; i >= 0; i--) {
        if(maxN & (1<<i)) {
            op = i+1;
            break;
        }
    }
    return (~(a&b)) & bin(op);
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k, cnt = 0, list[500005] = {};
    bool used[500005] = {};
    cin >> n >> k;
    for(int i=0; i < n; i++) {
        cin >> list[i];
    }
    for(int i = 0; i < n; i++) {
        int p = list[i], use = 0;
        for(int j = 0; j < n; j++) {
            if(j > i) {
                p = Xor(list[j], p);
            }
            if(!used[i] && i <= j) {
                if(p == k) {
                    cnt++;
                    us(used, i, j);
                    break;
                }
            }

        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
