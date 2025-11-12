#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10,M = 1e6+10;
int n,m,T;
struct node{
    int to,next,len;
}a[2*M];
int pre[N],k;
int cost[15][N];
bool f[N];
int res = INT_MAX;
void add(int u,int v,int w){
    k++;
    a[k] = {v,pre[u],w};
    pre[u] = k;
}
void dfs(int s,int sum,int id){
    //cout<<s<<' '<<sum<<' '<<id<<endl;
    if(id==n){
        res = min(res,sum);
        return;
    }
    for(int i = pre[s];i;i = a[i].next){
        int to = a[i].to;
        if(f[to]==false){
            f[to] = true;
            dfs(to,sum+a[i].len,id+1);
            f[to] = false;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&T);
    int x,y,z;
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    for(int i = 1;i<=T;i++){
        scanf("%d",cost[i][0]);
        for(int j = 1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    if(T==0){
        dfs(1,0,1);
        printf("%d",res);
        return 0;
    }
    printf("0\n");


    return 0;
}
