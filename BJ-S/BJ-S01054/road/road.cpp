#include<bits/stdc++.h>
#define N 10020
#define M 15
using namespace std;
struct edge{
    int u,v;
    long long w;
};
bool operator <(edge a,edge b){
    return a.w>b.w;
}
priority_queue<edge>q;
vector<edge> e[N],tree[N];
int vis[N],mem[N],ali[M]={0};
int n,m,k;
int f=0;
void mt(int x,int n1){
    memset(vis,0,sizeof(vis));
    memset(mem,0,sizeof(mem));
    for(int i=0;i<e[x].size();i++){
        q.push((edge){e[x][i].u,e[x][i].v,e[x][i].w});
    }
    vis[x]=1;
    while(n1>1){
        while(!q.empty()&&(vis[q.top().v]||(q.top().v>n&&ali[q.top().v-n]==0))){
            q.pop();

        }
        if(q.empty()){
            break;
        }
        edge temp=q.top();
        q.pop();
        if(!mem[temp.u]){
            tree[temp.u].clear();
            mem[temp.u]=1;
        }
        tree[temp.u].push_back((edge){temp.u,temp.v,temp.w});
        vis[temp.v]=1;
        for(int i=0;i<e[temp.v].size();i++){
            q.push((edge){e[temp.v][i].u,e[temp.v][i].v,e[temp.v][i].w});
        }
        n1--;
    }
    return;
}
long long now=0;
void check(int x){
    if(vis[x]){
        return;
    }
    vis[x]=1;
    for(int i=0;i<tree[x].size();i++){
        now+=tree[x][i].w;
        check(tree[x][i].v);
    }
    return;
}
int c[M],a[M][N];
int two[11]={1,2,4,8,16,32,64,128,266,512,1024};
long long mint(int n){
    mt(1,n);
    now=0;
    memset(vis,0,sizeof(vis));
    check(1);
    return now;
}
long long ans=100000000000000000;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        e[u].push_back((edge){u,v,w});
        e[v].push_back((edge){v,u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            e[n+i].push_back((edge){n+i,j,a[i][j]});
            e[j].push_back((edge){j,n+i,a[i][j]});
        }
    }
    for(int i=0;i<=two[k-1];i++){
        int i2=i,t=1,js=0;
        long long na=0;
        memset(ali,0,sizeof(ali));
        while(i2){
            if(i2%2==1){
                ali[t]=1;
                na+=c[t];
                js++;
            }
            i2>>=1;
        }
        na+=mint(n+js);
        if(na<ans){
            ans=na;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
