
#include<bits/stdc++.h>
using namespace std;
struct road
{
    int to,w;
};
int n,m,k,c[11],a[11][10001],x,y,z,rmin[10001];
long long ans=0,leizhu=LONG_LONG_MAX;
bool ok[10001],flag[11];
vector<road> v[10001];
int main()
{
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<pow(2,k);i++)
    {
        ans=0;
        for(int j=1;j<=k;j++)
        {
            if(i/(int)(pow(2,j-1))%2)
            {
                flag[j]=1;
                ans+=c[j];
            }
            else
            {
                flag[j]=0;
            }
        }
        memset(rmin,0x3f,sizeof(rmin));
        memset(ok,true,sizeof(ok));
        queue<int> q;
        q.push(1);
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            for(int j=0;j<v[fr].size();j++)
            {
                rmin[v[fr][j].to]=min(v[fr][j].w,rmin[v[fr][j].to]);
                if(ok[v[fr][j].to])
                {
                    ok[v[fr][j].to]=0;
                    q.push(v[fr][j].to);
                }
            }
            if(i!=0)
            {
                for(int j=1;j<=n;j++)
                {
                    int tmp=INT_MAX;
                    for(int l=1;l<=n;l++)
                    {
                        if(flag[l])
                        {
                            tmp=min(tmp,a[l][fr]+a[l][j]);
                        }
                    }
                    rmin[j]=min(tmp,rmin[j]);
                    if(ok[j])
                    {
                        ok[j]=0;
                        q.push(j);
                    }
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            ans+=rmin[j];
        }
        leizhu=min(ans,leizhu);
    }
    cout<<leizhu;
}