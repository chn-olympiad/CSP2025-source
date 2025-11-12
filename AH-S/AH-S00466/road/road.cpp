#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node{
    int u,v,cost;
}road[1111111];

struct node2{
    int u2,v2,cost2;
}road2[1111111];

int n,m,k,n1,n2,money,cnt=0,cnt2;
int huafei[15],fa[111111];
int jianli[15][11111];
long long ans=999999999;
bool jian[15];

bool cmp(node2 x,node2 y){
    return x.cost2<y.cost2;
}

void add(int x,int y){
    cnt++;
    road[cnt].u=x;
    road[cnt].v=y;
    road[cnt].cost=money;
}

void add2(int x,int y,int z){
    cnt2++;
    road2[cnt2].u2=x;
    road2[cnt2].v2=y;
    road2[cnt2].cost2=z;
}

int findfa(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=findfa(fa[x]);
}

void build(int x,int y){
    fa[x]=findfa(fa[y]);
    findfa(x);
}

long long jieguo(){
    long long sum=0;
    for(int a=1;a<=n+k;a++){
        fa[a]=a;
    }
    for(int a=1;a<=cnt;a++){
        road2[a].u2=road[a].u;
        road2[a].v2=road[a].v;
        road2[a].cost2=road[a].cost;
    }
    int enddd=0;
    for(int a=1;a<=k;a++){
        if(jian[a]){
            enddd++;
        }
    }
    cnt2=cnt;
    for(int a=1;a<=k;a++){
        if(jian[a]){
            sum+=huafei[a];
            for(int b=1;b<=n;b++){
                add2(n+a,b,jianli[a][b]);
            }
        }
    }
    sort(road2+1,road2+cnt2+1,cmp);
    int sss=0;
    for(int a=1;a<=cnt2;a++){
        if(fa[road2[a].u2]==fa[road2[a].v2]){
            continue;
        }else{
            build(road2[a].u2,road2[a].v2);
            sum+=road2[a].cost2;
            sss++;
        }
        if(sss==n+enddd-1){
            return sum;
        }
    }
    return 999999999;
}

void DFS(int x){
    if(x>k){
        ans=min(ans,jieguo());
        return ;
    }
    jian[x]=false;
    DFS(x+1);
    jian[x]=true;
    DFS(x+1);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int a=1;a<=m;a++){
        cin>>n1>>n2>>money;
        add(n1,n2);
    }
    for(int a=1;a<=k;a++){
        cin>>huafei[a];
        for(int b=1;b<=n;b++){
            cin>>jianli[a][b];
        }
    }
    DFS(1);
    cout<<ans;
}
