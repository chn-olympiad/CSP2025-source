#include<bits/stdc++.h>
#define int long long
using namespace std;
bool a[501];
int b[501];
bool v[501];
int df[501];
int n,m;
int dfs(int x)
{
    if(x == n)
    {
        //for(int i = 1;i<=n;i++)
        //{
        //    cout<<df[i]<<' ';
        //}
        //cout<<endl;
        int l = 0;
        int cnt = 0;
        for(int i = 1;i<=n;i++)
        {
            if(df[i]>cnt && a[i])
            {
                l++;
            }
            else
            {
                cnt++;
            }
            if(l>=m)
            {
                return 1;
            }
        }
        return 0;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        if(!v[i])
        {
            v[i] = 1;
            df[i] = b[x+1];
            ans += dfs(x+1);
            df[i] = 0;
            v[i] = 0;
        }
        ans = ans%998244353;
    }
    return ans;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //int n,m;
    cin>>n>>m;
    int cnt = 0;
    for(int i = 1;i<=n;i++)
    {
        char c;
        cin>>c;
        int x = c-'0';
        a[i] = x;
        if(a[i])
            cnt++;
           // cout<<a[i];
    }
    int cnt0 = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
      //  cout<<b[i]<<' ';
      //  if(b[i] == 0)
    }
    if(m == n)
    {
        if(!cnt == n)
            cout<<0<<endl;
        return 0;
    }
    int ans = dfs(0);
    cout<<ans<<endl;
    return 0;
}
