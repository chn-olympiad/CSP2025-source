#include <bits/stdc++.h>
using namespace std;
int t;
const int N = 1e5 + 7;
int n;
long long dp[N][3];
long long ans,cnt,num,sum;
bool vis[N],vis2[N];


struct Node{
    int take;
    int id;
}a[N],b[N],c[N];


bool cmp(Node aa,Node bb) {
    return aa.take > bb.take;
}

int main() {
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool flag = 0;
        for(int i = 1;i <= n;++i) {
            cin >> a[i].take >> b[i].take >> c[i].take;
            if(b[i].take != 0) flag = 1;
        }
        if(!flag) {
                sort(a + 1,a + n + 1,cmp);
            for(int i = 1;i <= (n / 2);++i) {
                ans += a[i].take;
            }
            cout << ans << endl;
        } else {
            for(int i = 1;i <= n;++i) {
                dp[i][0] = max({dp[i - 1][0] + a[i].take,dp[i - 1][1] + a[i].take,dp[i - 1][2] + a[i].take});
                dp[i][1] = max({dp[i - 1][0] + b[i].take,dp[i - 1][1] + b[i].take,dp[i - 1][2] + b[i].take});
                dp[i][2] = max({dp[i - 1][0] + c[i].take,dp[i - 1][1] + c[i].take,dp[i - 1][2] + c[i].take});
            }
            cout << max({dp[n][0],dp[n][1],dp[n][2]}) << endl;
        }

    }
    return 0;
}
