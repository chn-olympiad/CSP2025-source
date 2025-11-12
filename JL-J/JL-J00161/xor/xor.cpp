#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 5e5 + 5;

int n, k;
int val[N];
int sum[N];
unordered_map <int, vector <int> > pos; 
int f[N];

void bemax(int &a, int b) {
    a = a > b ? a : b;
}

int find(int i) {
    int tar = k ^ sum[i];
    int l = 0, r = pos[tar].size() - 1;

    if (pos[tar].empty() || pos[tar][0] >= i)
        return -1;

    while (l < r) {
        int mid = l + r + 1 >> 1;

        if (pos[tar][mid] < i)
            l = mid;
        else
            r = mid - 1;
    }

    return pos[tar][r];
}

void inp() {
    scanf("%d%d", &n, &k);
    pos[0].push_back(0);

    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &val[i]);
        sum[i] = sum[i - 1] ^ val[i];
        pos[sum[i]].push_back(i);
    }
}

void work() {
    for (int r = 1; r <= n; r ++ ) {
        f[r] = f[r - 1];
        int l = find(r);

        if (~l)
            bemax(f[r], f[l] + 1);
    }

    printf("%d\n", f[n]);
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}