#include <iostream>
using namespace std;

struct NODE{
    int matchedN = 0;
    int matched[10005] = { };
    int roadCost[10005] = { };
}Node[10005];

bool b[10005],sum = 0;

void dfs(int p){
    bool flag = false;
    for(int i = 1; i <= Node[p].matchedN; i++){
        if(!b[Node[p].matched[i]]){
            flag = true;
        }
    }
    //cout <<flag << " ";
    if(!flag){
        cout << sum;
        return;
    }

    for(int i = 1; i <= Node[p].matchedN; i++){
        if(!b[Node[p].matched[i]]){
            b[Node[p].matched[i]] = true;
            sum += Node[p].roadCost[i];
            dfs(Node[p].matched[i]);
            b[Node[p].matched[i]] = false;
            sum -= Node[p].roadCost[i];
        }
    }
    return;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,m,k;
    cin >> n >> m >>k;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        Node[u].matched[++Node[u].matchedN] = v;
        Node[v].matched[++Node[v].matchedN] = u;
        Node[u].roadCost[Node[u].matchedN] = w;
        Node[v].roadCost[Node[v].matchedN] = w;
    }
    if(k == 0){
        dfs(1);
    }
    return 0;
}
