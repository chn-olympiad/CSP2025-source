#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 7;
int t, n, k, ans, a[N][4], box[4], flag[N], sub[N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        memset(box, 0, sizeof box);
        cin >> n;
        ans = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            int d, b, c;
            cin >> d >> b >> c;
            a[i][1] = d, a[i][2] = b, a[i][3] = c;
            if(d >= b && d >= c) cnt++, box[1]++, flag[i] = 1, ans += d;
            else if(b >= d && b >= c) cnt++, box[2]++, flag[i] = 2, ans += b;
            else if(c >= d && c >= b) cnt++, box[3]++, flag[i] = 3, ans += c;
        }
        if(box[1] > n / 2) k = 1;
        if(box[2] > n / 2) k = 2;
        if(box[3] > n / 2) k = 3;
        for(int i = 1; i <= n; i++)
            if(k == flag[i]) sub[i] = a[i][k] - max(a[i][k % 3 + 1], a[i][5 - k - (k % 3)]);
            else sub[i] = 2e9;
        sort(sub + 1, sub + n + 1);
        for(int i = 1; i <= box[k] - n / 2; i++)
            ans -= sub[i];
        cout << ans << endl;
    }
    return 0;
}
