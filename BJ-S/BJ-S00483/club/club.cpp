#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int t, n, sum, cnt[3];

struct node1 {
    int num, id;
};

struct node2 {
    node1 a[3];
} p[100005];

bool cmp1(node1 x, node1 y) {
    return x.num > y.num;
}

bool cmp2(node2 x, node2 y) {
    if (x.a[0].num == y.a[0].num) {
        if (x.a[1].num == y.a[1].num) {
            return x.a[2].num > y.a[2].num;
        }
        return x.a[1].num > y.a[1].num;
    }
    return x.a[0].num > y.a[0].num;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while (t--) {
        sum = 0;
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            //p[i].maxv = -0x3f3f3f3f;
            for (int j = 0; j < 3; j++) {
                cin >> p[i].a[j].num;
                p[i].a[j].id = j;
            }
            sort(p[i].a, p[i].a + 2, cmp1);
        }
        sort(p + 1, p + n + 1, cmp2);
        for (int i = 1; i <= n; i++) {
            if (cnt[p[i].a[0].id] < n / 2) {
                sum += p [i].a[0].num;
                cnt[p[i].a[0].id]++;
            } else if (cnt[p[i].a[1].id] < n / 2) {
                sum += p[i].a[1].num;
                cnt[p[i].a[1].id]++;
            } else {
                sum += p[i].a[2].num;
                cnt[p[i].a[2].id]++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
