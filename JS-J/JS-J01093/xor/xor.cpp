#include <bits/stdc++.h>
using namespace std;

int _xor(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    int indexa = 1, indexb = 1, sum = 0;
    bool ea[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, eb[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, ans[25];
    while (a) ea[indexa++] = a % 2, a /= 2;
    while (b) eb[indexb++] = b % 2, b /= 2;
    for (int i = 1; i < max(indexa, indexb); i++) ans[i] = ea[i] != eb[i];
    for (int i = 1; i < max(indexa, indexb); i++) sum += ans[i] * pow(2, i - 1);
    return sum;
}

bool dif(int as, int al, int bs, int bl) {
    return (as + al - 1 < bs || bs + bl - 1 < as);
}

struct node {
    int start, len;
    bool sel;
};

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, a[500003], ans = 0;
    vector<node> vec;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            int sum = 0;
            for (int k1 = i; k1 < i + j; k1++) sum = _xor(sum, a[k1]);
            if (sum == k) {
                vec.push_back(node{i, j, false});
                break;
            }
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        vec[i].sel = true;
        ans++;
        for (int j = 0; j < i; j++) {
            if (vec[i].sel)
                if (!dif(vec[i].start, vec[i].len, vec[j].start, vec[j].len)) {
                    vec[i].sel = false;
                    ans--;
                    break;
                }
        }
    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
