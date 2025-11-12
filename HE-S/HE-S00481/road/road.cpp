#include<bits/stdc++.h>
using namespace std;

typedef unordered_map<int,unordered_map<int,int>> umap;





struct pr
{
    int first = 0;
    int second = 0;

    pr()
    {

    }

    pr(int a,int b)
    {
        first = a;
        second = b;
    }

    pr(int a[])
    {
        first = a[0];
        second = a[1];
    }

    bool operator > (const pr&other)const
    {
        return first > other.first;
    }

    bool operator<(const pr&other)const
    {
        return first<other.first;
    }


};

bool cmp(pr a,pr b)
{
    return a.first <= b.first;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    umap graph;

    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 0; i<m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for(int i = 1; i<=k; i++)
    {
        int c;
        cin >> c;
        graph[n+i][0] = c;
        for(int j = 1; j<=n; j++)
        {
            int a;
            cin >> a;
            graph[n+i][j] = a + c;
            graph[j][n+i] = a + c;
        }
    }


    int visit_cnt = 0;
    vector<bool> visited(n+k+1,false);
    visited[0] = true;

    unsigned long long sum = 0;

    priority_queue<pr,vector<pr>,greater<pr>> que;
    que.push({0,1});

    while(visit_cnt != n)
    {
        pr top = que.top();
        int current = top.second;
        if(visited[current])
        {
            que.pop();
            continue;
        }
        sum += top.first;
        visited[current] = true;


        if(current<=n)
        {
            visit_cnt++;
            for(auto&x:graph[current])
            {
                if(!visited[x.first]) que.push({x.second,x.first});
            }
            que.pop();

        }
        else
        {

            for(auto&x:graph[current])
            {
                if(!visited[x.first]) que.push({x.second - graph[current][0],x.first});
            }
            que.pop();
        }


    }

    cout << sum;

    return 0;

}
