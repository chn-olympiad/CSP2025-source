#include<bits/stdc++.h>
using namespace std;
using lint = long long;
const int N = 1e5 + 10;
struct Node
{
    lint val;
    vector<int> num;
};
lint st[N][4];
vector<Node> dp[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node tmp;
    int t,n;
    lint maxn = -1;
    cin >> t;
    while(t--)
    {
        memset(st,0,sizeof(st));
        for(int i = 1;i <= n;i++)
        {
            while(dp[i].size() > 0)
            {
                dp[i].erase(dp[i].begin());
            }
        }
        tmp.num.resize(3);
        tmp.num[0] = tmp.num[1] = tmp.num[2] = tmp.val = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> st[i][1] >> st[i][2] >> st[i][3];
            st[i][0] = (st[i][1] > st[i][2] and st[i][1] > st[i][3]) ? 1 : (st[i][2] > st[i][3] ? 2 : 3);
        }
        dp[0].push_back(tmp);
        for(int i = 1;i <= n;i++)
        {
            for(auto j : dp[i - 1])
            {
                tmp.num = j.num;
                for(int k = 1;k <= 3;k++)
                {
                    tmp.num[k - 1]++;
                    if(tmp.num[k - 1] > n / 2)
                    {
                        tmp.num[k - 1]--;
                        continue;
                    }
                    tmp.val = j.val + st[i][k];
                    dp[i].push_back(tmp);
                    tmp.num[k - 1]--;
                }
            }
        }
        maxn = -1;
        for(auto i : dp[n])
        {
            maxn = max(maxn,i.val);
        }
        cout << maxn << '\n';
    }
    return 0;
}
