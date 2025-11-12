#include <bits/stdc++.h>
#define N 100010
#define endl '\n'
using namespace std;
int T;
int n;
int a[N][4];
int fans;
bool o1, o2, o3;
int s1[N], s2[N], s3[N];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        o1 = 1;
        o2 = 1;
        o3 = 1;
        fans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> a[i][j];
                if(j == 1 and a[i][j] != 0) {
                    o1 = 0;
                }
                else if(j == 2 and a[i][j] != 0) {
                    o2 = 0;
                }
                else if(j == 3 and a[i][j] != 0) {
                    o3 = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            s1[i] = a[i][1];
            s2[i] = a[i][2];
            s3[i] = a[i][3];
        }
        if(!o1 && o2 && o3) {
            sort(s1 + 1, s1 + n + 1);
            cout << s1[n] + s1[n - 1] << endl;
            continue;
        }
        else if(!o2 && o1 && o3) {
            sort(s2 + 1, s2 + n + 1);
            cout << s2[n] + s2[n - 1] << endl;
            continue;
        }
        else if(!o3 && o1 && o2) {
            sort(s3 + 1, s3 + n + 1);
            cout << s3[n] + s3[n - 1] << endl;
            continue;
        }
        if(n == 2) {
            int ans = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(i != j) {
                        ans = max(ans, (a[1][i] + a[2][j]));
                    }
                }
            }
            cout << ans << endl;
        }
        else {
            for(int i = 1; i <= n; i++) {
                fans += max(max(a[i][1], a[i][2]), a[i][3]);
            }
            cout << fans << endl;
        }
    }
}
