#include <bits/stdc++.h>
using namespace std;
int a[1005], ans[15][15];
bool cmp(int a, int b) {
	return a > b;
}
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int na = n * m;
    for (int i = 1; i <= na; i++) {
        cin >> a[i];
    }
    int R = a[1]; 
    sort(a + 1, a + na + 1, cmp);
    int cnt = 1;
    int x = 1;
    for (int i = 1; i <= n; i++) {
		
        if(cnt % 2 != 0) {
            for (int j = 1; j <= m; j++) {
                ans[j][i] = a[x];
                x++;
            }
            cnt++;
        }
        else{
            for (int j = m; j >= 1; j--) {
                ans[j][i] = a[x];
                x++;
            }
            cnt++;
        }
        
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == R) {
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
