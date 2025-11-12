#include <bits/stdc++.h>

using namespace std;
int t;
int n;

struct ppl{
    int a, b, c;
} p[100005];

int acnt, bcnt, ccnt;
long long ans;

bool cmp(ppl x, ppl y) {
    int zerox = 0, zeroy = 0;
    if (x.a == 0) zerox++; if (x.b == 0) zerox++; if (x.c == 0) zerox++;
    if (y.a == 0) zeroy++; if (y.b == 0) zeroy++; if (y.c == 0) zeroy++;
    if (zerox > zeroy) return 1;
    else if (zerox < zeroy) return 0;

    int maxx[5], maxy[5];
    maxx[0] = x.a; maxx[1] = x.b; maxx[2] = x.c;
    maxy[0] = y.a; maxy[1] = y.b; maxy[2] = y.c;
    sort(maxx, maxx+3);
    sort(maxy, maxy+3);
    if (maxx[2] == maxy[2]) {
        if (maxx[1] == maxy[1]) return maxx[0] > maxy[0];
        return maxx[1] > maxy[1];
    }
    return maxx[2] > maxy[2];
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        acnt = 0; bcnt = 0; ccnt = 0;
        scanf("%d", &n);
        bool zero3 = true;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
            if (p[i].c != 0) zero3 = false;
        }
        if (n <= 10) {
            for (int i = 0; i < (int)pow(3, n); i++) {
                long long sum = 0;
                int j;
                while (i) {
                    int val = i % 3;
                    i /= 3;
                    if (val == 0) {
                        acnt++;
                        sum += p[j].a;
                    } else if (val == 1) {
                        bcnt++;
                        sum += p[j].b;
                    } else {
                        ccnt++;
                        sum += p[j].c;
                    }
                    j++;
                }
                if (acnt <= n/2 && bcnt <= n/2 && ccnt <= n/2) {
                    ans = max(ans, sum);
                }
            }
        } else if (zero3) {
            for (int i = 0; i < (1 << n); i++) {
                long long sum = 0;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        bcnt++;
                        sum += p[j].b;
                    } else {
                        acnt++;
                        sum += p[j].a;
                    }
                }
                if (acnt <= n/2 && bcnt <= n/2) {
                    ans = max(ans, sum);
                }
            }
            cout << ans << endl;
        } else {
            sort(p, p+n, cmp);
            for (int i = 0; i < n; i++) {
                int maxn = max(p[i].a, max(p[i].b, p[i].c));
                if (acnt < n/2 && maxn == p[i].a) {
                    acnt++;
                    ans += p[i].a;
                } else if (bcnt < n/2 && p[i].b > p[i].c) {
                    bcnt++;
                    ans += p[i].b;
                } else {
                    ccnt++;
                    ans += p[i].c;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
