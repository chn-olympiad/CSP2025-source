#include <bits/stdc++.h>

int t, n, a1[100001], a2[100001], a3[100001], s1[100001], s2[100001], s3[100001];

struct temp {
    struct value {
        int val, int d;
        bool operator < (const value a) {
            return val < a.val;
        }
    } v[3];
} tmp[100001];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    //freopen("club.in", "r", stdin);
    //freopen("club.out", "w", stdout);

    std::cin >> t;
    while(t--) {
        int sta[3], ans = 0;
        bool ban[3];
        for(int i = 0; i < 3; i++) {
            sta[i] = 0;
        }
        for(int i = 0; i < 3; i++) {
            ban[i] = false;
        }
        std::cin >> n;
        for(int i = 1; i <= n; i++) {
            std::cin >> a1[i] >> a2[i] >> a3[i];
        }

        std::sort(a1 + 1, a1 + n + 1, cmp);
        std::sort(a2 + 1, a2 + n + 1, cmp);
        std::sort(a3 + 1, a3 + n + 1, cmp);
        for(int i = 1; i <= n; i++) {
            s1[i] = s1[i - 1] + a1[i];
            s2[i] = s2[i - 1] + a2[i];
            s3[i] = s3[i - 1] + a3[i];
        }
        for(int i = 1; i <= n; i++) {
            int wmnxl = std::max(a1[i] - (s1[n] - s1[n - s1[sta[tmp[i].v[0].d]] - 1]), std::max(a2[i] - (s2[n] - s2[sta[tmp[i].v[1].d]]), a3[i] - (s3[n] - s3[sta[tmp[i].v[2].d]])));
            tmp[i].v[0].val = (a1[i] - (s1[n] - s1[n - d1 - 1]));
            tmp[i].v[0].d = 0;
            tmp[i].v[1].val = (a2[i] - (s2[n] - s1[n - d2 - 1]));
            tmp[i].v[1].d = 1;
            tmp[i].v[2].val = (a3[i] - (s3[n] - s3[n - d3 - 1]));
            tmp[i].v[2].d = 2;
            sort(tmp[i].v, tmp[i].v + 3);
            sta[tmp[i].v[2].d]++;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                if(sta[j] >= d / 2) {
                    ban[j] = true;
                }
            }
            sta[tmp[i].v[2].d]++;
            if(tmp[i].v[2].d == 0) {
                ans += a1[i];
            }
            if(tmp[i].v[2].d == 1) {
                ans += a2[i];
            }
            if(tmp[i].v[2].d == 2) {
                ans += a3[i];
            }
        }
        std::cout << ans << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
