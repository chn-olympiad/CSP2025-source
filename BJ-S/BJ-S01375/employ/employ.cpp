#include<bits/stdc++.h>
using namespace std;
int c[510];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    sort(c + 1, c + 1 + n);
    int ans = 1;
    if (m == n){
        int cnt = 1;
        for (int i = 1; i <= n; i++){
            if (c[i] != c[i - 1]){
                ans *= cnt;
                cnt = 1;
            }
            else
                cnt++;
        }
        ans *= cnt;
    }
    cout << ans << '\n';

    return 0;
}