#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int N =1e5 + 10;
int dp[105][105][105];
int dpb[3000][3000];

struct node{
    int fst, snd, trd;
}a[N];

bool cmp(const node &a, const node &b){
    return a.fst > b.fst;
}

void oper(){
    bool flaga = true;
    bool flagb = true;
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(dpb, 0, sizeof(dpb));
    int n;
    int ans = -1;
    cin >> n;
    int MAXX = n / 2;
    for (int  i = 1; i <= n; i++){
        cin >> a[i].fst >> a[i].snd >> a[i].trd;
        if(a[i].snd != 0 || a[i].trd != 0) flaga = false;
        if (a[i].trd != 0) flagb = false;
    }
    if(flaga == true){
        ans = 0;
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= MAXX; i++){
            ans += a[i].fst;
        }
        cout << ans;
    }
    else if (flagb == true){
        dpb[0][0] = 0;
        for (int f = 1; f <= n; f++){
            for (int i = MAXX; i >= 0; i--){
                for (int j = min (MAXX, n - i); j >= 0; j--){
                    if (i - 1 >= 0) dpb[i][j] = max(dpb[i][j], dpb[i - 1][j] + a[f].fst);
                    if (j - 1 >= 0) dpb[i][j] = max(dpb[i][j], dpb[i][j - 1] + a[f].snd);
                    if (f == n){
                        ans = max(ans, dpb[i][j]);
                    }
                }
            }

        }
    cout << ans << endl;
    }
    else {
        dp[0][0][0] = 0;
        for (int f = 1; f <= n; f++){
            for (int i = MAXX; i >= 0; i--){
                for (int j = MAXX; j >= 0; j--){
                    for (int k = min(MAXX, n - i - j); k >= 0; k--){
                        if (i - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[f].fst);
                        if (j - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[f].snd);
                        if (k - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[f].trd);
                        if (f == n){
                            ans = max(ans, dp[i][j][k]);
                        }
                    }
                }
            }

        }
    cout << ans << endl;
    }
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        oper();
    }

    return 0;
}
