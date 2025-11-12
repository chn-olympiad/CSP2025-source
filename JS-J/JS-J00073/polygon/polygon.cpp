#include <bits/stdc++.h>
#define int long long
const int MOD = 998244353;
using namespace std;
int n,a[5002];
int ans;
set<vector<int>> st;
vector<int> path;
void dfs(int mx, int sum, int i, int cnt)
{
    if(sum > mx * 2 && cnt >= 3) {
            if(st.count(path) == 0)
            {
                ans = (ans+1)%MOD;
                st.insert(path);
            }
    }
    if(i > n) {
        return ;
    }
    path.push_back(a[i]);
    dfs(max(mx,a[i]),sum+a[i],i+1,cnt + 1);
    path.pop_back();
    dfs(mx,sum,i+1,cnt);
    return ;
}
/*
5
1 2 3 4 5
*/
signed main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);scanf("%lld",n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%lld",&a[i]);
    }
    dfs(0,0,1, 0);
    printf("%lld",ans);
    return 0;
}
