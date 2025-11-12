

#include <bits/stdc++.h>

using namespace std;

int t = 0;
int n = 0;
int pd[9];
int THREE[19];
long long p[9];
int q[9];
long long ans = 0;

struct node {
    int one;
    int two;
    int thr;
};
node a[100009];
node cha[100009];

void make () {
    THREE[1]++;
    for (int i = 1; i <= n; i++) {
        if (THREE[i]>=3) {
            THREE[i+1]+=THREE[i]/3;
            THREE[i]%=3;
        }

    }
}

void check () {
    for (int i = 1; i <= pow(3,n); i++) {
        make();
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        for (int j = 1; j <= n; j++) {
            if (THREE[j] == 0) {
                p[1] += a[j].one;
                q[1]++;
            }
            if (THREE[j] == 1) {
                p[2] += a[j].two;
                q[2]++;
            }
            if (THREE[j] == 2) {
                p[3] += a[j].thr;
                q[3]++;
            }
        }
        if (q[1]<=n/2&&q[2]<=n/2&&q[3]<=n/2) {
            ans = max(ans, p[1]+p[2]+p[3]);
        }
    }
    cout << ans << endl;
}

bool px (node x, node y) {
    return max(x.one, max(x.two,x.thr)) > max(x.one, max(x.two,x.thr));
}

bool px2 (node x, node y) {
    return x.thr>y.thr;
}

void init () {
    ans = 0;
    for (int i = 1; i <= 5; i++) {
        p[i] = 0;
        q[i] = 0;
        pd[i] = 0;
    }
    for (int i = 1; i <= 12; i++) {
        THREE[i] = 0;
    }
    for (int i = 1; i <= n+2; i++) {
        cha[i].one = 0;
        cha[i].two = 0;
        cha[i].thr = 0;
    }
}

int main () {

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--) {
        init();

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].one >> a[i].two >> a[i].thr;
            if (a[i].one!=0) {
                pd[1]++;
            }
            if (a[i].two!=0) {
                pd[2]++;
            }
            if (a[i].thr!=0) {
                pd[3]++;
            }
        }
        if (n<=10) {
            check();
        }
        if (pd[2]==0&&pd[3]==0) {
            sort(a+1,a+n+1, px);
            long long sum = 0;
            for (int i = 1; i <= n/2; i++) {
                sum += a[i].one;
            }
            cout << sum << endl;
        }
        if (pd[3] == 0) {
            for (int i = 1; i <= n; i++) {
                cha[i].thr = abs(a[i].one-a[i].two);
                cha[i].one = a[i].one;
                cha[i].two = a[i].two;
            }
            sort(cha+1,cha+n+1, px2);
            long long sum = 0;
            for (int i = 1; i <= n; i++) {
                if (q[1]==n/2) {
                    q[2]++;
                    sum+=cha[i].two;
                }
                else if (q[2]==n/2) {
                    q[1]++;
                    sum+=cha[i].one;
                }
                else if (cha[i].one>=cha[i].two) {
                    q[1]++;
                    sum+=cha[i].one;
                }
                else {
                    q[2]++;
                    sum+=cha[i].two;
                }
            }
            cout << sum << endl;
        }
    }

    return 0;
}
