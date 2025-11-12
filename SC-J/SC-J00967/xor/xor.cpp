#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int num[N], calc[N][N];
bool chose[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i; j < n; j++)
            calc[j - i][i] = c ^= num[j];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; i + j < n; j++)
            if (calc[i][j] == k) {
                bool flag = true;
                for (int k = j; k <= i + j; k++)
                    if (chose[k]) {
                        flag = false;
                        break;
                    }
                if (flag) {
                    cnt++;
                    for (int k = j; k <= i + j; k++)
                        chose[k] = true;
                }
            }
    printf("%d", cnt);
    return 0;
}