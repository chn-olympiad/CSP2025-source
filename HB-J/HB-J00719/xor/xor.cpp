// xor.cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 1023;
int n, k, a[N], tot;

struct Node {
    int start, end;
} b[N];

bool cmp(Node x, Node y) {
    if (x.end != y.end) return x.end < y.end;
    return x.start < y.start;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;

    if (n <= int(5e3 + 1023)) {
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++) {
            int sum = a[i];
            if (sum == k) b[++tot] = {i, i};
            else {
                int j;
                for (j = i + 1; j <= n && sum != k; j++)
                    sum ^= a[j];
                if (sum == k) b[++tot] = {i, j - 1};
            }
        }

        sort(b + 1, b + tot + 1, cmp);
        int cnt = 0, end = 0;

        for (int i = 1; i <= tot; i++) {
            if (end < b[i].start) {
                end = b[i].end;
                cnt++;
            }
        }

        cout << cnt << '\n';
    } else {
        int ans1 = 0, ans2 = 0, ans3 = 0;

        // ans1 -> a[i] = k
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == k) ans1++;
        }

        // ans2 -> 1 ~ n
        int sum = a[1];
        for (int i = 2; i <= n; i++) {
            if (sum == k) {
                sum = a[i];
                ans2++;
            } else
                sum ^= a[i];
        }

        if (sum == k) ans2++;

        // ans3 -> n ~ 1
        sum = a[n];
        for (int i = n - 1; i; i--) {
            if (sum == k) {
                sum = a[i];
                ans3++;
            } else
                sum ^= a[i];
        }

        if (sum == k) ans3++;

        cout << max(ans1, max(ans2, ans3)) << '\n';
    }

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
