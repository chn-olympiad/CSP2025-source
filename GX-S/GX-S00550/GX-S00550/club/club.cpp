#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T, n, ans;
bool f1 = false, f2 = false, f3 = false;
int ant, bnt, cnt;
int q[N][5];
int main(){
	freopen("club.in", "w", stdin);
	freopen("club.out", "r", stdout);
    cin >> T;
    while(T--){
        ant = 0;
        bnt = 0;
        cnt = 0;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) q[i][j] = 0;
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) cin >> q[i][j];
        for(int i = 1; i <= n; i++) ans += max(max(q[i][1], q[i][2]), q[i][3]);
        cout << ans << endl;
    }
    return 0;
}
