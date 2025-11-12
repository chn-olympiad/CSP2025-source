#include <bits/stdc++.h>
using namespace std;
struct qj{
    int l,r;
} q[500100];
int t = 0;
int a[500100];
int dp[2000][2000];
bool b[500100];
bool cmp1(qj a, qj b){
    if(a.r - a.l != b.r - b.l)return a.r -a.l < b.r - b.l;
    return a.l < b.l;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        dp[i][i] = a[i];
        if(dp[i][i] == k){
            t ++;
            q[t] .l = i;
            q[t] .r = i;
        }
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = i + 1;j <= n;j ++)
        {
            dp[i][j] = dp[i][j - 1] ^ a[j];
            if(dp[i][j] == k){
                t ++;
                q[t] .l = i;
                q[t] .r = j;
             }
        }
    }
    sort(q + 1, q + 1 + t, cmp1);
    /*for(int i = 1;i <= t;i ++)
    {
        cout << q[i].l << " "<< q[i].r;
        cout << "\n";
    }*/
    int sum = 0;
    for(int i = 1;i <= t;i ++)
    {
        bool flag = true;
        for(int j = q[i].l;j <= q[i].r;j ++)
        {
            if(b[j])flag = false;
        }
        if(flag){
            for(int j = q[i].l;j <= q[i].r;j ++)
            {
                b[j] = true;
            }
            sum ++;
        }
    }
    cout << sum ;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
