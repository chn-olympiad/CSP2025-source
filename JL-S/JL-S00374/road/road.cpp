#include <vector>
#include <iostream>
using namespace std;

vector<int> dt[11111];
vector<int> td[11111];
int dis[11111];
int zjh[100];
bool w[11111];
int n,m,k,s;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        dt[x].push_back(y);
        td[x].push_back(z);
        dt[y].push_back(x);
        td[y].push_back(z);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>zjh[i];
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            dt[n+j].push_back(j);
            td[n+j].push_back(x);
            dt[j].push_back(n+j);
            td[j].push_back(x+zjh[i]);
        }
    }
    for(int i=2;i<=n+k;i++)
    {
        dis[i]=99999999;
    }
    for(int i=1;i<=n+k;i++)
    {
        int mi=99999999,t;
        for(int j=1;j<=n+k;j++)
        {
            if(dis[j]<mi&&w[j]==0)
            {
                mi=dis[j];
                t=j;
            }
        }
        w[t]=1;
        s+=dis[t];
        for(int j=0;j<dt[t].size();j++)
        {
            int v=dt[t][j];
            dis[v]=min(dis[v],td[t][j]);
        }
    }
    cout<<s;
    return 0;
}
