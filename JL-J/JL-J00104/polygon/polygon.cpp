#include<bits/stdc++.h>

using namespace std;

int n;
int sum;
int cnt;
int maxx;
int a[5010];

int pailie(int x, int y) {
    int sum2 = x + y;
    int maxa = 0;
    int cnt2 = 0;
    maxa = max(x, y);
    for(int i = y + 2; i < n; i++) {
        sum2 += i;
        maxa = max(maxa, i);
        for(int j = i + 1; j < n; j++) {
            sum2 += j;
            maxa = max(maxa, j);
        }
        if(sum2 > 2 * maxa) {
            cnt2++;
            cnt2 = cnt2 % 998244353;
        }
        sum2 = 0;
        maxa = max(x, y);
    }
    return cnt2;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 2; j < n; j++) {
            for(int k = i; k <= j; k++) {
                sum += a[k];
                if(maxx < a[k]) {
                    maxx = a[k];
                }
            }
            if(sum > 2 * maxx) {
                cnt++;
                cnt = cnt % 998244353;
            }
        }
        for(int j = i + 1; j < n; j++) {
            cnt += pailie(i, j);
            cnt = cnt % 998244353;
        }
    }
    cout << cnt << endl;
    return 0;
}
