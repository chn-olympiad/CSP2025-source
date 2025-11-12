#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int ans[n][m],a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            cin >> ans[i][j];
        }
    }
    a = ans[0][0];
    sort(ans,ans + n * m - 1);
    int r, c, cnt;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == a) {
                r = (i * m + j) / n + 1;
                if (r % 2 == 1) c = (i * m + j) % n + 1;
                else c = n - (i * m + j) % n + 1;
            }
        }
    }

    cout << c << " " << r << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
