#include<bits/stdc++.h>
#define int long long
using namespace std;

int par[10010];
int gt(int x){
    if(par[x] == x) return x;
    return par[x] = gt(par[x]);
}
void merg(int a, int b){
    par[gt(b)] = gt(a);
}



struct PIR{
    int first;
    int second;
    int third;
    int fourth;
};
PIR mkPIR(int a, int b, int c, int d){
    PIR res;
    res.first = a;
    res.second = b;
    res.third = c;
    res.fourth = d;
    return res;
}
int dis[1024][10010];
vector<PIR> bian[10010];
int diskk[11][10010];

bool operator > (PIR a, PIR b){
    return a.second < b.second;
}
bool operator < (PIR a, PIR b){
    return a.second > b.second;
}
priority_queue<PIR> todo;
bool vis[10010];
int N, M, K;
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &N, &M, &K);
    for(int i = 0; i <= N; i++){
        par[i] = i;
    }
    for(int i = 0; i < M; i++){
        int a, b, w;
        scanf("%lld%lld%lld", &a, &b, &w);
        bian[a].push_back(mkPIR(b, w, bian[b].size(), a));
        bian[b].push_back(mkPIR(a, w, bian[a].size() - 1, b));
    }
    for(int i = 0; i < K; i++){
        //只走Subtask A
        int j;
        scanf("%lld", &j);
        vector<int> frees;
        for(int j = 1; j <= N; j++){
            scanf("%lld", &diskk[i][j]);
            if(diskk[i][j] == 0) frees.push_back(j);
        }
        for(auto s:frees){
            map<int, bool> alreadyy;
            for(auto ch:bian[s]){
                alreadyy[ch.first] = 1;
                if(diskk[i][ch.first] < ch.second){
                    ch.second = diskk[i][ch.first];
                    bian[ch.first][ch.third].second = diskk[i][ch.first];
                }
            }
            for(int t = 1; t <= N; t++){
                if(t != s && !alreadyy[t]){
                    bian[s].push_back(mkPIR(t, diskk[i][t], bian[t].size(), s));
                    bian[t].push_back(mkPIR(s, diskk[i][t], bian[s].size() - 1, t));
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(auto ch:bian[i]){
            todo.push(ch);
        }
    }

    int ttl = 0;
    while(!todo.empty()){
        auto x = todo.top();
        todo.pop();
        int s = x.first, e = x.fourth;
        if(gt(s) != gt(e)){
            ttl += x.second;
            merg(s, e);
        }
    }

    printf("%lld", ttl);

    return 0;
}
