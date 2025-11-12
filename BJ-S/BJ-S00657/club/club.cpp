#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, maxval[100001], maxid[100001];

struct node {
    mutable int id, num;
} cnt[4];

struct node2 {
    mutable int id, num;
} d[100001];

bool cmp(node x, node y) {//node:greater:front
    return x.num > y.num;
}

bool cmp2(node2 x, node2 y) {
    return x.num < y.num;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        //cout << '#' << endl;
        cin >> n;
        for (int i = 0; i <= n; i++) {
            d[i].id = d[i].num = 0;
        }
        memset(maxval, 0, sizeof(maxval));
        memset(maxid, 0, sizeof(maxid));
        for (int i = 1; i <= 3; i++) {
            cnt[i].id = i;
            cnt[i].num = 0;
        }
        for (int i = 1; i <= n; i++) {
            node a[4];
            for (int j = 1; j <= 3; j++) {
                a[j].id = j;
                cin >> a[j].num;
            }
            sort(a + 1, a + 3 + 1, cmp);
            maxval[i] = a[1].num;
            maxid[i] = a[1].id;
            cnt[a[1].id].num++;
            d[i].id = i;
            d[i].num = a[1].num - a[2].num;
            //cout << d[i].num << endl;
        }
        sort(cnt + 1, cnt + 3 + 1, cmp);//coincidence:way->cmp:same
        //cout << cnt[1].id << " " << cnt[1].num << endl;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += maxval[i];
            //cout << i << " " << maxval[i] << endl;
        }
        if (cnt[1].num <= n / 2) {
            cout << sum << endl;
            continue;
        }
        //exist sth > n/2
        int delta = cnt[1].num - n / 2;
        //cout << delta << endl;
        sort(d + 1, d + n + 1, cmp2);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            //cout << maxid[i] << " " << cnt[1].id << endl;
            if (maxid[d[i].id] == cnt[1].id) {
                sum -= d[i].num;
                //cout << i << endl;
                cur++;
                if (cur >= delta) {
                    break;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
/*
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
