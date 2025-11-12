#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n,max_new_limit;
int new_member[MAXN][3];
int dp[MAXN];
int counter[3];

int sum = 0;

void dfs(int k) {
    int selected = -1;
    if (k != 0)  dp[k] = dp[k-1];
    // printf("\n----dfs(%d) start----\n",k);
    for (int i=0;i<3;i++) {
        
        if (counter[i] <= max_new_limit) {
            if (new_member[k][i] == 0) {
                continue;
            }
            sum = max(sum,k);
            dp[k] = max(dp[k], dp[k-1] + new_member[k][i]);
            if (dp[k] == dp[k-1] + new_member[k][i]) {
                selected = i;
                counter[selected] ++;
                if (k+1 < n) dfs(k+1);
                counter[selected] --;
            };
            // printf("k=%d i=%d dp=%d nm=%d\n",k,i,dp[k],new_member[k][i]);
        }
        if (k+1 < n && selected == -1) dfs(k+1);
    }
    // printf("selected=%d\n",selected);
    // if (selected != -1) counter[selected] ++;
    // if (k+1 < n) dfs(k+1);
    // if (selected != -1) counter[selected] --;
    
}

void solve() {
    scanf("%d",&n);
    max_new_limit = n / 2;
    for (int i=0;i<n;i++) {
        scanf("%d%d%d",&new_member[i][0],&new_member[i][1],&new_member[i][2]);
    }
    memset(dp,-1,sizeof(dp));
    memset(counter,0,sizeof(counter));
    // dp[0] = 0;
    dfs(0);
    printf("%d\n",dp[sum]);
}

int main() {
    int k;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&k);
    for (int i=0;i<k;i++) {
        sum = 0;
        solve();
    }
}