#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t, n;

int dif[N], winner[N];
int cnt[4];

struct node {
    int id, val;
}v[4];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%d", &t);
    while (t -- ) {
        for (int i = 1; i <= 3; i ++ ) cnt[i] = 0;
        scanf("%d", &n);

        long long res = 0;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= 3; j ++ ) {
                scanf("%d", &v[j].val);
                v[j].id = j;
            }

            sort(v + 1, v + 4, [](node a, node b) {
                return a.val > b.val;
            });
            res += v[1].val;
            winner[i] = v[1].id;
            cnt[winner[i]] ++ ;
            dif[i] = v[1].val - v[2].val;
        }

        int bound = n / 2;
        int flag = -1;
        for (int i = 1; i <= 3; i ++ )
            if (cnt[i] > bound) 
                flag = i;

        if (flag != -1) {
            vector<int> tmp;
            for (int i = 1; i <= n; i ++ )
                if (winner[i] == flag)
                    tmp.push_back(dif[i]);

            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < cnt[flag] - bound; i ++ )
                res -= tmp[i];
        }
        printf("%lld\n", res);
    }

    return 0;
}