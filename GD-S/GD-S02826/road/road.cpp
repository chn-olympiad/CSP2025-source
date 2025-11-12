#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct Edge 
{
    int u,v,w;
    bool operator<(const Edge& other) const 
	{
        return w < other.w; 
    }
};
vector<int> parent;
vector<int> rank_;
int find(int x) 
{
    if (parent[x] != x) 
	{
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
// 并查集合并
void unite(int x, int y) 
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank_[x] < rank_[y]) 
	{
        parent[x] = y;
    } else {
        parent[y] = x;
        if (rank_[x] == rank_[y]) 
		{
            rank_[x]++;
        }
    }
}
int main() 
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<Edge> edges;
    for(int i=0;i<m;i++) 
	{
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int total_nodes=1+n+k; 
    for (int j=1;j<=k;j++) 
	{
        int cj;
        cin >> cj;
        int town_node = n + j; 
        edges.push_back({0,town_node,cj});
        for (int i = 1; i <= n; ++i) 
		{
            int aj_i;
            cin >> aj_i;
            edges.push_back({town_node,i,aj_i});
        }
    }
    parent.resize(total_nodes);
    rank_.resize(total_nodes,0);
    for(int i=0;i<total_nodes;i++) 
	{
        parent[i]=i;
    }
    sort(edges.begin(),edges.end());
    int min_cost=0;
    int components=n; 
    for (const Edge&e:edges) 
	{
        int u_root=find(e.u);
        int v_root=find(e.v);
        if (u_root!=v_root) 
		{
            bool u_is_city=(e.u>=1&&e.u<=n);
            bool v_is_city=(e.v>=1&&e.v<=n);
            if (u_is_city&&v_is_city) 
			{
                if(u_root!=v_root) 
				{
                    components--;
                }
            } 
			else if(u_is_city)
			{
                bool has_city=false;
                for(int i=1;i<=n;i++) 
				{
                    if(find(i)==v_root) 
					{
                        has_city=true;
                        break;
                    }
                }
                if(has_city) components--;
            } 
			else if(v_is_city) 
			{
                bool has_city=false;
                for (int i=1;i<=n;i++) 
				{
                    if(find(i)==u_root) 
					{
                        has_city=true;
                        break;
                    }
                }
                if(has_city) components--;
            }
            unite(u_root,v_root);
            min_cost+=e.w;
            if(components==1) 
			{
                break;
            }
        }
    }
    cout<<min_cost<<endl;
    return 0;
}
