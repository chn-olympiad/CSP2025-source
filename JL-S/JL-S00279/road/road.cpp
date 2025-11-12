#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
const int N=1e6+10;
int u[N],v[N],w[N];
int c[20],a[20][100010];
bool f[20];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int t;
            for(t=1;t<=m;t++)
                if((u[t]==i&&v[t]==j)||(u[t]==i&&v[t]==j))
                    break;
            int mv=INT_MAX;
            if(t<=m) mv=w[t];
            for(t=1;t<=k;t++)
            {
                int x=a[t][i]+a[t][j];
                if(!f[t])
                {
                    x+=c[t];
                    f[t]=true;
                }
                mv=min(mv,x);
            }
            ans+=mv;
        }
    }
    cout<<ans;
    return 0;
}
