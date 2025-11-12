#include<bits/stdc++.h>
using namespace std;

struct node{
    int a, b, c;
};
/*
const int MAX = 1e5+5;
node club[MAX*3];
int pos = 1;
bool flag[MAX];
*/

bool cmp(node A, node B){
    if(A.a > B.a) return true;
    return false;
}

node num[100000+5];

const int MAX = 200+5;
int dp[MAX][MAX];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> num[i].a >> num[i].b >> num[i].c;
        }
        
        if(n <= 2){
            for(int i = 1; i <= n; i++){
                for(int j = min(i, n/2); j >= 0; j--){
                    for(int k = min(i, n/2); k >= 0; k--){
                        if(i-j-k > n/2) continue;
                        if(i-j-k < 0) continue;

                        int x = 0;
                        if(j != 0) x = max(x, dp[j-1][k]+num[i].a);
                        if(k != 0) x = max(x, dp[j][k-1]+num[i].b);
                        if(i-j-k != 0) x = max(x, dp[j][k]+num[i].c);

                        dp[j][k] = x;
                    }
                }
/*
                for(int j = 0; j <= n/2; j++){
                    for(int k = 0; k <= n/2; k++) cout << dp[j][k] << ' ';
                    cout << endl;
                }
                cout << endl;*/
            }

            int ans = 0;
            for(int i = 0; i <= n/2; i++){
                for(int j = 0; j <= n/2; j++){
                    if(i <= n/2 && j <= n/2 && n-i-j <= n/2) ans = max(ans, dp[i][j]);
                }
            }

            cout << ans << '\n';

            memset(dp, 0, sizeof(dp));
        }
        else{
            sort(num+1, num+1+n, cmp);

            int ans = 0;
            for(int i = 1; i <= n/2; i++) ans += num[i].a;
            cout << ans << '\n';
        }
    }

    return 0;
}