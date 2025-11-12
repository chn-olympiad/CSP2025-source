#include<bits/stdc++.h>
using namespace std;

int n, m, k;
long long ans;
int f[10004];
int city_w[11][10004];// ³ÇÊÐ»¯ 
struct node{
    int u, v;
    long long w;
    bool operator<(const node a) const {
        return a.w < w;
    }
};
priority_queue<node> pq;

int find(int x){
    return (f[x]==x?x:f[x]=find(f[x]));
}

void add(int x,int y){
    int fx=find(x), fy=find(y);
    if(fx == fy){
        return;
    }
    f[fx] = fy;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1;i<=n;i++){
        f[i] = i;
    }
    for(int i=0, u, v, w;i<m;i++){
        scanf("%d %d %d", &u, &v, &w);
        pq.push({u, v, w});
    }
    for(int i=1;i<k;i++){
        for(int j=0;j<=n;j++){
            scanf("%d", &city_w[i][j]);
        }
    }
    while(!pq.empty()){
        node x = pq.top();
        pq.pop();
        if(find(x.u) == find(x.v)){
            continue;
        }
        ans += x.w;
        add(x.u, x.v);
    }
    printf("%lld\n", ans);
    return 0;
}

