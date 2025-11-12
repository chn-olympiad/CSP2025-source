#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[10005];
int cost1[10005][10005];
int cost2[10005][10005];
void Dijkstra(int start,vector<vector<pair<int,int>>> road)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(start,0));
    v[start]=1;
    while(!pq.empty())
    {
        pair<int,int> tmp=pq.front();
        pq.pop();
        for(pair<int,int> i:road[tmp.first])
        {
            if(!v[i.first])
            {
                i.second+=tmp.second;
                pq.push(i);
                v[i.first]=1;
                cost1[start][i.first]=i.second;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    vector<vector<pair<int,int>>> road(n);
    vector<pair<int,vector<pair<int,int>>>> c(k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        road[u].push_back(make_pair(v,w));
        road[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",c[i].first);
        for(int j=1;j<=n;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            c[i].second.push_back(tmp);
        }
    }
    for(int i=0;i<n;i++)
    {
        Dijkstra(i,road);
    }
    int ans;
    for(int i[10005]:cost1)
    {
        for(int j:i)ans+=j;
    }
    printf("%d",ans);
    return 0;
}
