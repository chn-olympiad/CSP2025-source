#include<bits/stdc++.h>

using namespace std;

int n, m;
struct node {
    int a, b, c;
};
node bef[105];
int ans1, ans2;
int ikun;

int cmp(node a1, node b1) {
    return a1.a > b1.a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int cnt = n * m;
    for(int i = 1; i <= cnt; i++) {
        cin >> bef[i].a;
        bef[i].b = i;
    }
    sort(bef + 1, bef + cnt + 1, cmp);
    for(int i = 1; i <= cnt; i++) {
        bef[i].c = i;
    }
    for(int i = 1; i <= cnt; i++)
        if(bef[i].b == 1)
            ikun = bef[i].c;
    int num = ikun % n;
    if(num == 0) {
        ans1 = ikun / n;
    } else {
        ans1 = ikun / n + 1;
    }
    ans2 = ikun % m;
    if(ans2 == 0) {
        ans2 = n;
    } else if(ans2 == 1 && ans1 % 2 == 0) {
        ans2 = n;
        cout << ans1 << ' ' << ans2 << '\n';
        return 0;
    } else if(ans2 % 2 == 0) {
        ans2 = n - ikun % 2;
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}
