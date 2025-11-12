#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,minw=999999999,mini,cost;
//int edge[1000005][3];
bool vis[10005];
vector<vector <int> > edge;
int main()
{
    memset(vis,0,sizeof(vis));
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    edge.resize(m+2);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        edge[i].push_back(u);
        edge[i].push_back(v);
        edge[i].push_back(w);
    }
    //sort(edge.begin(),edge.end(),cmt);
    /*
    for(int i=0;i<m;++i)
    {
        printf("%d %d %d\n",edge[i][0],edge[i][1],edge[i][2]);
    }
    */

    for(int j=0;j<=n;++j)
    {
        minw=999999999;
        for(int i=0;i<m;++i)
        {
            if(edge[i][2]<minw&&(vis[edge[i][0]]==false||vis[edge[i][1]]==false))
            {
                minw=edge[i][2];
                mini=i;
            }
        }
        if(minw==999999999)
        {
            printf("%d",cost);
            return 0;
        }
        vis[edge[mini][0]]=true;
        vis[edge[mini][1]]=true;
        cost+=minw;

    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
