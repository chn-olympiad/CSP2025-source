#include <bits/stdc++.h>
using namespace std;

struct node{
int v,w;
};

struct edge{
int u,v,w;
};

vector<edge> e;
//vector<node>g [10010];
int c[20][100010];
int a[20000];

int f(int x){
    if(x==a[x]){
        return x;
    }
    return a[x]=f(a[x]);
}

void uni(int x,int y){
    int xx=f(x);
    int yy=f(y);
    if(xx!=yy){
        a[xx]=yy;
    }
}

bool cmp(edge x,edge y){
    return x.w<y.w;
}

bool res[20];

long long sim(vector<edge> ne, int n,int k){
    for(int i=0;i<=n-k+1;i++){
        a[i]=i;
    }
    for(int i=10010;i<=10010+k;i++){
        a[i]=i;
    }

    long long sum=0;
sort(ne.begin(),ne.end(),cmp);

    int con=0;
    int m=ne.size();
    for(int i=0;i<m;i++){
        if(f(ne[i].u)!=f(ne[i].v)){
            uni(ne[i].u,ne[i].v);
            con++;
            sum+=ne[i].w;
        }
        if(con>=n)break;
    }
    return sum;
}

long long minm=INT_MAX;

void dfs(int dep,int n,int k){
    if(dep>k){
        long long st=0;
        vector<edge> ne=e;
        int cnt=0;
        for(int i=1;i<=k;i++){
                //printf("%d ",res[i]);
            if(res[i]){
                    cnt++;
                st+=c[i][0];
                for(int j=1;j<=n;j++){
                    ne.push_back({j,10010+i,c[i][j]});
                }
            }

        }
        long long ans=sim(ne,cnt+n,cnt);

        //printf("->%lld\n",ans);
        minm=min(minm,st+ans);
        return;
    }
    res[dep]=false;
    dfs(dep+1,n,k);
    res[dep]=true;
    dfs(dep+1,n,k);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,n,k;
    //printf("aaa");
    scanf("%d%d%d",&n,&m,&k);
    //printf("aaa");
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        //g[u].push_back({v,w});
        //g[v].push_back({u,w});
        e.push_back({u,v,w});
    }
    //p//rintf("aaa");
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            scanf("%d",&c[i][j]);
        }
    }

    long long sum=0;
    if(k==0){
            for(int i=0;i<=n;i++){
        a[i]=i;
    }
        sort(e.begin(),e.end(),cmp);
    int con=0;
    for(int i=0;i<m;i++){
        if(f(e[i].u)!=f(e[i].v)){
            uni(e[i].u,e[i].v);
            con++;
            sum+=e[i].w;
        }
        if(con>=n)break;
    }
    printf("%lld",sum);
    }else{
        dfs(1,n,k);
        printf("%lld",minm);
    }
    //printf("aaa");



}
