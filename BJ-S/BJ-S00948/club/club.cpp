#include <bits/stdc++.h>
using namespace std;
int n, t, a[5][1000005], f[505][505][505], ans;
struct N
{
    int id, x;

}c[1000005];
bool cmp(N a, N b)
{
    return a.x>b.x;
}
void dfs(int a1, int a2, int a3, int k, int sum)
{
    if(k==n+1) {ans=max(ans, sum);return;}
    for(int i=1;i<=3;i++)
    {
        if(a1) dfs(a1-1, a2, a3, k+1, sum+a[1][k]);
        if(a2) dfs(a1, a2-1, a3, k+1, sum+a[2][k]);
        if(a3) dfs(a1, a2, a3-1, k+1, sum+a[3][k]);
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--)
    {
        int k1=0, k2=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[j][i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(a[j][i]>0)
                {
                    k1=1;
                    if(j==3){k2=1;break;}
                }
            }
        }
        if(!k1)
        {
            sort(a[1]+1, a[1]+n+1);
            for(int i=1;i<=n/2;i++)
            ans+=a[1][i];
            cout<<ans<<"\n";
            continue;
        }
        if(!k2)
        {
            for(int i=1;i<=n;i++) c[i].id=i, c[i].x=a[1][i]-a[2][i];
            sort(c+1, c+n+1, cmp);
            for(int i=1;i<=n;i++)
            {
                if(i<=n/2) ans+=a[1][i];
                else ans+=a[2][i];
            }
            cout<<ans<<"\n";
            continue;
        }
        /*for(int p=1;p<=n;p++)
        {
            for(int i=max(0, n/2-p);i<=n/2;i++)
            {
                for(int j=max(0, n/2-p+i);j<=n/2;j++)
                {
                    for(int k=max(0, n/2-p+i+j);k<=n/2;k++)
                    {
                        f[i][j][k]=max(f[i][j][k], max(f[i+1][j][k]+a[1][i], max(f[i][j+1][k]+a[2][i], f[i][j][k+1]+a[3][i])));
                        ans=max(ans, f[i][j][k]);
                    }
                }
            }
        }
        cout<<ans;*/
        dfs(n/2, n/2, n/2, 1, 0);
        cout<<ans<<"\n";
    }

    return 0;
}
