#include <bits/stdc++.h>
using namespace std;

int ans[3];

struct s {
    int a, b, c;
    int as, bs, cs;
};

bool f(s a, s b) {
    return max({a.a, a.b, a.c}) > max({b.a, b.b, b.c});
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        int cnt = 0;
        int n;
        cin >> n;

        int d = n / 2;

        s arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i].a >> arr[i].b >> arr[i].c;
        }

        sort(arr, arr + n, f);

        for(int i = 0; i < n; i++) {
            int maxn = max({arr[i].a, arr[i].b, arr[i].c});
            if(maxn == arr[i].a) {
                arr[i].as = 1;

                if(arr[i].b > arr[i].c) {
                    arr[i].bs = 2;
                    arr[i].cs = 3;
                }
                else {
                    arr[i].bs = 3;
                    arr[i].cs = 2;
                }
            }
            else if(maxn == arr[i].b) {
                arr[i].bs = 1;

                if(arr[i].a > arr[i].c) {
                    arr[i].as = 2;
                    arr[i].cs = 3;
                }
                else {
                    arr[i].as = 3;
                    arr[i].cs = 2;
                }
            }
            else {
                arr[i].cs = 1;

                if(arr[i].b > arr[i].a) {
                    arr[i].bs = 2;
                    arr[i].as = 3;
                }
                else {
                    arr[i].bs = 3;
                    arr[i].as = 2;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(arr[i].as == 1 && ans[0] < d) {
                cnt += arr[i].a;
                ans[0]++;
            }
            else if(arr[i].bs == 1 && ans[1] < d) {
                cnt += arr[i].b;
                ans[1]++;
            }
            else if(arr[i].cs == 1 && ans[2] < d) {
                cnt += arr[i].c;
                ans[2]++;
            }
            else {
                break;
            }
        }

        cout << cnt << endl;

    }

    return 0;
}
