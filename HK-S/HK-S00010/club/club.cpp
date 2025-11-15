#include <bits/stdc++.h>
using namespace std;

int main () {
    FILE *in = fopen("club.in", "r");
    FILE *out = fopen("club.out", "w");

    int t;
    fscanf(in, "%d", &t);

    for (int data = 0; data < t; data++) {
        int n;
        fscanf(in, "%d", &n);

        int r[3][n];

        for (int i = 0; i < n; i++) {
            int a1, a2, a3;
            fscanf(in, "%d%d%d", &a1, &a2, &a3);
            r[0][i] = a1;
            r[1][i] = a2;
            r[2][i] = a3;
        }

        int rq = n / 2;

        int used[n];
        memset(used, -1, sizeof(used));
        int vals[n];
        memset(vals, 0, sizeof(vals));
        int res[3];
        memset(res, 0, sizeof(res));
        int cnt[3];
        memset(cnt, 0, sizeof(cnt));

        bool flag = true;
        while (flag) {

            int rmax[3], rmaxidx[3];
            memset(rmax, -1, sizeof(rmax));
            int rmax2[3];
            int rloss[3];
            memset(rmax2, -1, sizeof(rmax2));

            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < n; i++) {
                    if (used[i] != -1) continue;
                    if (r[j][i] > rmax[j]) {
                        rmax[j] = r[j][i];
                        rmaxidx[j] = i;
                    }
                }
                if (rmax[j] == -1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;


            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < n; i++) {
                    if (used[i] != -1) continue;
                    if (i == rmaxidx[j]) continue;
                    if (r[j][i] > rmax2[j]) {
                        rmax2[j] = r[j][i];
                    }
                }
            }

            for (int j = 0; j < 3; j++) {
                rloss[j] = rmax[j] - rmax2[j];
                if (cnt[j] >= rq) {
                    rloss[j] = -1;
                }
            }

            int maxloss = max(rloss[0], max(rloss[1], rloss[2]));
            int maxlossidx;

            if (maxloss == rloss[0])
                maxlossidx = 0;
            else if (maxloss == rloss[1])
                maxlossidx = 1;
            else if (maxloss == rloss[2])
                maxlossidx = 2;

            int dupe[3];
            memset(dupe, 0, sizeof(dupe));
            for (int i = 0; i < 3; i++) {
                if (maxlossidx == i) continue;
                if (maxloss == rloss[i]) {
                    dupe[i] = true;
                    if (!dupe[maxlossidx]) dupe[maxlossidx] = true;
                }
            }

            int maxduped = 0;
            for (int i = 0; i < 3; i++) {
                if (dupe[i]) {
                    if (rloss[i] > maxduped) {
                        maxduped = rloss[i];
                        maxlossidx = i;
                    }
                }
            }
            
            int val = rmax[maxlossidx];
            vals[rmaxidx[maxlossidx]] = val;
            used[rmaxidx[maxlossidx]] = maxlossidx;
            res[maxlossidx] += val;
            cnt[maxlossidx] += 1;

            // printf("%d: + %d = %d; used %d\n", maxlossidx, val, res[maxlossidx], rmaxidx[maxlossidx]);
        }
        
        bool f = true;
        while (f == true) {
            f = false;
            for (int i = 0; i < n; i++) {
                int use = used[i];
                int rmax = max(r[0][i], max(r[1][i], r[2][i]));
                int rmaxi;
                if (rmax == r[0][i])
                    rmaxi = 0;
                else if (rmax == r[1][i])
                    rmaxi = 1;
                else if (rmax == r[2][i])
                    rmaxi = 2;
                
                if (rmaxi == use) continue;
                if (cnt[rmaxi] >= rq) continue;
                cnt[rmaxi] += 1;
                cnt[use] -= 1;
                res[rmaxi] += rmax;
                res[use] -= vals[i];
                used[i] = rmaxi;
                // printf("%d: swapped %d and %d : -%d +%d\n", i, rmaxi, use, vals[i], rmax);
                f = true;
            }
        }

        int ans = res[0] + res[1] + res[2];

        fprintf(out, "%d\n", ans);
        
    }
}