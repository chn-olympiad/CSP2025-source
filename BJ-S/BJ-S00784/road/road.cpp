#include <bits/stdc++.h>
using namespace std;
int a[10100][10100]={0};
int t[10100];
int m,n,k,ans=0;
bool g[10100]={false};
int sum=0;
void dfs(int l)
{
    bool h=false;
    for(int i=1 ; i<=n ; i++)
    {
        if(!g[i])
        {
            h=true;
            g[i] = true;
            sum += a[l][i];
            dfs(i);
            g[i] = false;
            sum -= a[l][i];
        }
    }
    if(h == false)
    {
        if(ans == 0)
            ans=sum;
        else
            ans=min(ans,sum);
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;

    for(int i=1 ; i<=m ; i++)
    {
        int b,c,d;
        cin >>b >>c >> d;
     //   cout << a[b][c] << endl;
        if(a[b][c] == 0)
        {
            a[b][c] = d;
            a[c][b] = d;
        }

        else
        {
            a[b][c]=min(a[b][c],d);
            a[c][b]=min(a[c][b],d);
        }
  //      cout << a[b][c] << endl;
   //     cout << a[c][b] << endl;
    }


    for(int i=0 ; i<k ; i++)
    {
        int b;
        cin >> b;
        for(int i=1 ; i<=n ; i++)
        {
            cin >> t[i];
        }
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=n ; j++)
            {
                if(i == j) continue;
                int sum=b+t[i]+t[j];
                if(a[i][j] == 0) a[i][j]=sum;
                else a[i][j] = min(a[i][j],sum);
            }

        }
    }
    g[1] = true;
    dfs(1);
    cout << ans << endl;
    return 0;
}
