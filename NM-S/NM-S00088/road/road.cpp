#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct path{
    int id,to,value=0,extra_cost=0;
};

struct node{
    int id;
    vector<path> outs;
};

node nodes[10030];
bool is_extra_cost_used[1200000];
bool is_cost_used[1200000];
int n,m,k;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    //Input
    scanf(" %d %d %d",&n,&m,&k);
    for (int i=0;i<m;i++){
        int u,v,w;
        path new_path1,new_path2;
        scanf(" %d %d %d",&u,&v,&w);
        new_path1.id = new_path2.id = i;
        new_path1.to = v;new_path2.to = u;
        new_path1.value = new_path2.value = w;
        nodes[u].outs.push_back(new_path1);nodes[v].outs.push_back(new_path2);
        is_cost_used[i] = false;
    }
    for (int i=0;i<k;i++){
        int extra_cost;
        scanf("%d",&extra_cost);
        for (int j=1;j<=n;j++){
            path new_path1,new_path2;
            int value;
            scanf("%d",&value);
            new_path1.value = new_path2.value = value;
            new_path1.to = i;new_path2.to = 10000 + i;
            new_path1.id = new_path2.id = 1000000+i*10+j;
            new_path1.extra_cost = new_path2.extra_cost = extra_cost;
            nodes[10000+i].outs.push_back(new_path1);
        }
    }

    //BFS
    cout<<0;

    return 0;
}
