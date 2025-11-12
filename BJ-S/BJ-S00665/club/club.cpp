#include "bits/stdc++.h"
using namespace std;
//#define int long long
const int N = 1e5+100;
int T;
struct Node
{
    int a1,a2,a3;
};
Node a[N];
int n;
int dfs(int n1,int n2,int n3,int ans)
{
    if(n1+n2+n3 >= n)
        return ans;
    if(n1 < n/2)
    {
        if(n2 < n/2)
        {
            if(n3 < n/2)
                return max(dfs(n1+1,n2,n3,ans+a[n1+n2+n3+1].a1),max(dfs(n1,n2+1,n3,ans+a[n1+n2+n3+1].a2),dfs(n1,n2,n3+1,ans+a[n1+n2+n3+1].a3)));
            else
                return max(dfs(n1+1,n2,n3,ans+a[n1+n2+n3+1].a1),dfs(n1,n2+1,n3,ans+a[n1+n2+n3+1].a2));
        }
        else
        {
            if(n3 < n/2)
                return max(dfs(n1+1,n2,n3,ans+a[n1+n2+n3+1].a1),dfs(n1,n2,n3+1,ans+a[n1+n2+n3+1].a3));
            else
                return dfs(n1+1,n2,n3,ans+a[n1+n2+n3+1].a1);
        }
    }
    else
    {
        if(n2 < n/2)
        {
            if(n3 < n/2)
                return max(dfs(n1,n2+1,n3,ans+a[n1+n2+n3+1].a2),dfs(n1,n2,n3+1,ans+a[n1+n2+n3+1].a3));
            else
                return dfs(n1,n2+1,n3,ans+a[n1+n2+n3+1].a2);
        }
        else
        {
            if(n3 < n/2)
                return dfs(n1,n2,n3+1,ans+a[n1+n2+n3+1].a3);
            else
                return ans;
        }
    }
}
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
    cout << dfs(0,0,0,0) << "\n";
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--)
        solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
