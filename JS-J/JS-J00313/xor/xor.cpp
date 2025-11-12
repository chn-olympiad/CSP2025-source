#include<bits/stdc++.h>
using namespace std;

int a[500005];
int dp[500005],f[500005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    queue <int> q;
    for(int i = 1;i <= n;i++)
    {
        bool flag = 0;
        q.push(a[i]);
        if(a[i] == k) flag = 1,f[i] = 0;
        for(int j = 1;j < i;j++)
        {
            int t = q.front() ^ a[i];
            if(!flag && t == k) f[i] = j,flag = 1;
            q.push(t),q.pop();
        }
        if(!flag) f[i] = -1;
    }
    for(int i = 1;i <= n;i++)
        dp[i] = max(dp[i - 1],f[i] == -1 ? 0 : dp[i - f[i] - 1] + 1);
    cout << dp[n] << endl;
    return 0;
}
