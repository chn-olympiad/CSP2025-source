#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n,m,g,k;
int s[N * N],a[N][N];
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> m >> n;
    for(int i = 1;i <= n * m;i ++) cin >> s[i];
    k = s[1];
    sort(s + 1,s + 1 + n * m,cmp);
    for(int i = 1;i <= n;i ++) {
        if(i & 1)
            for(int j = 1;j <= m;j ++) {
                a[i][j] = s[++ g];
                if(s[g] == k) {
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
        else 
            for(int j = m;j;j --) {
                a[i][j] = s[++ g];
                if(s[g] == k) {
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
    }
    return 0;
}