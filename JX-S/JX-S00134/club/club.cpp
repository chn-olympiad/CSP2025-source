#include<bits/stdc++.h>
using namespace std;
int a1[100001],a2[100001],a3[100001];int n;
int ans = 0;
void dfs(int s,int d1,int d2,int d3,int sum)
{
    if(s == n+1)
    {
        ans = max(ans,sum);
        return;
    }
    if(d1<n/2)
    {
        dfs(s+1,d1+1,d2,d3,sum+a1[s]);
    }if(d2<n/2)
    {
        dfs(s+1,d1,d2+1,d3,sum+a2[s]);
    }if(d3<n/2)
    {
        dfs(s+1,d1,d2,d3+1,sum+a3[s]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        bool b = 1;
        for(int i = 1;i<=n;i++)
        {
            cin >> a1[i] >> a2[i] >> a3[i];
            if(a2[i]!=0||a3[i]!=0)b = 0;
        }
        if(b)
        {
            sort(a1+1,a1+n+1);
            int ans2 = 0;
            for(int i = n;i>n/2;i--)
            {
                ans2+= a1[i];
            }
            cout << ans2;
            return 0;
        }
        dfs(1,0,0,0,0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
