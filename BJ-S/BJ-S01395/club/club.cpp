#include <bits/stdc++.h>
#define ll long long
#define ull unsign ll
#define lb long double
using namespace std;

int t;
int n, ans;

int a1[100010];
int a2[100010];
int a3[100010];

void dfs(int now, int s1, int s2, int s3, int sum){
    if (now == n){
        ans = max(ans, sum);
        return;
    }
    if (s1 < n / 2)
        dfs(now + 1, s1 + 1, s2, s3, sum + a1[now + 1]);
    if (s2 < n / 2)
        dfs(now + 1, s1, s2 + 1, s3, sum + a2[now + 1]);
    if (s3 < n / 2)
        dfs(now + 1, s1, s2, s3 + 1, sum + a3[now + 1]);
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a1[i]>> a2[i] >> a3[i];
    if (n > 30){
        sort(a1 + 1, a1 + n + 1, greater<int>());
        sort(a2 + 1, a2 + n + 1, greater<int>());
        sort(a3 + 1, a3 + n + 1, greater<int>());
        int s1 = 0;
        int s2 = 0;
        int s3 = 0;
        for (int i = 1; i * 2 <= n; i++){
            s1 += a1[i];
            s2 += a2[i];
            s3 += a3[i];
        }
        if (s1 > s2){
            s2 = 0;
            for (int i = n / 2 + 1; i <= n; i++)
                s2 += a2[i];
            cout << s1 + s2 << endl;
        }
        else{
            s1 = 0;
            for (int i = n / 2 + 1; i <= n; i++)
                s1 += a1[i];
            cout << s1 + s2 << endl;
        }
    }
    else{
        ans = 0;
        dfs(0, 0, 0, 0, 0);
        cout << ans << endl;
    }
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
