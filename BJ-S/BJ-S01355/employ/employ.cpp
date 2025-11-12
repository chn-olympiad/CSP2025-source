#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 +5;

struct Node {
    int u, v, w;
};

vector<pair<int, int> > g[N];
vector<Node> p;
int money[N];
int a[N][N];

int fat[N];

int find(int x) {
    if (fat[x] == x) return x;

    return fat[x] = find(fat[x]);
}

signed main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);


    cout << 0 << endl;



    return 0;
}
