#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20;
const int M = 1e6 + 10;
int n,m,k;
struct node{
    int u, v,next,co;
}s[(M+N)*2];
int idx;
int pre[N];
int din[N];
int C[20];
int dk[N][20];
void add(int u, int v, int co){
    s[++idx] = {u, v,pre[u],co};
    din[v]++;
    pre[u] = idx;
}
queue<int>q;
int d[N];
int st;
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(d,0x3f,sizeof(d));
    scanf("%d%d%d", &n, &m,&k);
    int x,y,co;
    for(int i = 1;i <=m;i++){
        scanf("%d%d%d",&x,&y,&co);
        add(x,y,co);
    }
    for(int i = 1;i <=k;i++){
        scanf("%d",&C[i]);
        for(int j = 1;j <= n;j++){
            scanf("%d",&dk[j][i]);
        }
    }
    for(int i = 1;i <=n;i++){
        if(!din[i]){
            if(!st)st=i;
            q.push(i);
        }
    }
    d[st] = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i = pre[p];i;i=s[i].next){
            int to = s[i].v;
            int dis = s[i].co;
            for(int j = 1;j <= k;j++){
                dis = min(dis, C[j]+dk[p][j]+dk[to][j]);
            }
            dis+=d[p];
            if(dis<d[to]){
                d[to] = dis;
            ans+=d[to]-d[p];
            }din[to]--;
            if(!din[to])q.push(to);
        }
    }
    printf("%lld",ans);
    return 0;
}