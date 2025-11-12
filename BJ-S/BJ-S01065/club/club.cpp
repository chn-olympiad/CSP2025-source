#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN][3], c[MAXN];
int cnt[3];
priority_queue<int> pq;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        while (!pq.empty()){
            pq.pop();
        }
        cnt[0] = cnt[1] = cnt[2] = 0;
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            int num = max({a[i][0], a[i][1], a[i][2]});
            if (a[i][0] == num){
                c[i] = 0;
            }else if (a[i][1] == num){
                c[i] = 1;
            }else{
                c[i] = 2;
            }
            cnt[c[i]]++;
            ans += num;
        }
        int x = -1;
        for (int i = 0; i < 3; i++){
            if (cnt[i] > n / 2){
                x = i;
                break;
            }
        }
        if (x == -1){
            cout << ans << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++){
            if (c[i] == x){
                int num = -1e9;
                for (int j = 0; j < 3; j++){
                    if (j != x){
                        num = max(num, -a[i][x] + a[i][j]);
                    }
                }
                pq.push(num);
            }
        }
        while (cnt[x] > n / 2){
            cnt[x]--;
            ans += pq.top();
            pq.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}