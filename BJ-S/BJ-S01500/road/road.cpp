#include<bits/stdc++.h>
using namespace std;
struct node{
    long long id,v;
    friend bool operator < (node a,node b){
        return a.v > b.v;
    }
};
priority_queue <node> q;
vector <node> s[10015];
long long c[20];
long long d[20][10015];
long long vis[10015];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,flag = 1;
    cin >> n >> m >> k;
    for(int i = 1;i <= n + k;i++) vis[i] = -1;
    for(int i = 1;i <= m;i++){
        long long u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        s[u].push_back({v,w});
        s[v].push_back({u,w});
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        int cnt = 0;
        for(int j = 1;j <= n;j++){
            scanf("%lld",&d[i][j]);
            if(!d[i][j]) cnt = 1;
        }
        if(c[i] || !cnt) flag = 0;
    }
    for(int i = 1;i <= k;i++){
        for(int j = 1;j <= n;j++){
            s[i + n].push_back({j,d[i][j]});
            s[j].push_back({i + n,d[i][j]});
        }
    }
    q.push({1,0});
    long long ans = 0,num = 0;
    while(q.size()){
        node now = q.top();
        q.pop();
        if(vis[now.id] != -1) continue;
        vis[now.id] = 1;
        num++;
        //cout << now.id << " " << now.v << endl;
        ans += now.v;
        if(num == n + k) break;
        for(int i = 0;i < s[now.id].size();i++){
            if(vis[s[now.id][i].id] != -1) continue;
            q.push({s[now.id][i].id,s[now.id][i].v});
        }
    }
    cout << ans;
    return 0;
}
/*
4 5 0
1 2 10
1 3 6
1 4 7
2 4 1
3 4 9
0 1 10 10 0
*/
