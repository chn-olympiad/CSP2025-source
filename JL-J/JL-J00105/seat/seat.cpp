#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[1000001],dp[1001][1001];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int goal = a[1];
    sort(a+1,a+1+n*m);
    int t=n*m;
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[t] == goal)
            {
                cout<<j<<" "<<i;
                return 0;
            }
            dp[i][j] = a[t];
            t--;
        }
        j++;
        for(int i=n;i>=1;i--)
        {
            if(a[t] == goal)
            {
                cout<<j<<" "<<i;
                return 0;
            }
            dp[i][j] = a[t];
            t--;
        }
    }
    return 0;
}
