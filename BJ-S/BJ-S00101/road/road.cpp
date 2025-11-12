#include<bits/stdc++.h>
using namespace std;
const int M=1e6+1000000,N=1e4+100;
int n,m,k,mm;
struct node{
    int l,r,w,id;
    bool vis;
}road[M];
int fa[N];
bool vis[M];
int c[100];
int xuan[100];
bool q=1;
long long lans;
int visd[100];
int f(int i){
    if(fa[i]==i)return i;
    return fa[i]=f(fa[i]);
}
void chushi(){
    for(int i=1;i<=n+k;i++)fa[i]=i;
    return;
}
bool cmp(node a,node b){
    return a.w<b.w;
}
bool cmp2(node a,node b){
    return a.id<b.id;
}
long long check(){
    sort(road+1,road+mm+1,cmp);
    chushi();
    long long ans=0;
    for(int i=1;i<=mm;i++){
        if(road[i].vis==0)continue;
        int l=road[i].l;
        int r=road[i].r;
        if(f(l)==f(r))continue;
        fa[f(l)]=f(r);
        ans+=road[i].w;
    }
    sort(road+1,road+mm+1,cmp2);
    return ans;
}
void dfs(int step,int num){
    if(step==k+1){
        lans=min(lans,check()+num);
        return;
    }
    if(xuan[step]){
        dfs(step+1,num);
        return;
    }
    int i=step;
    for(int j=m+(i*n-n)+1;j<=m+i*n;j++)road[j].vis=1;
    dfs(step+1,num+c[step]);
    for(int j=m+(i*n-n)+1;j<=m+i*n;j++)road[j].vis=0;
    dfs(step+1,num);
    return;
}
int main(){
    freopen("road2.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>road[i].l>>road[i].r>>road[i].w;
        road[i].id=i;
    }
    mm=m+k*n;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0)q=0;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            road[m+(i-1)*n+j].l=n+i;
            road[m+(i-1)*n+j].r=j;
            road[m+(i-1)*n+j].w=w;
            road[m+(i-1)*n+j].id=m+(i-1)*n+j;
        }
    }
    if(q){
        sort(road+1,road+mm+1,cmp);
        chushi();
        long long ans=0;
        bool q2=0;
        for(int i=1;i<=mm;i++){
            int l=road[i].l;
            int r=road[i].r;
            if(f(l)==f(r))continue;
            fa[f(l)]=f(r);
            ans+=road[i].w;
            if(l>n)xuan[l-n]++;
            if(r>n)xuan[r-n]++;
            vis[i]=1;
        }
        for(int i=1;i<=mm;i++){
            int l=road[i].l;
            int r=road[i].r;
            if(l>n&&vis[i]==1&&xuan[l-n]==1)ans-=road[i].w;
            if(r>n&&vis[i]==1&&xuan[r-n]==1)ans-=road[i].w;
        }
        cout<<ans<<endl;
    }else{
        for(int i=1;i<=m;i++)road[i].vis=1;
        lans=check();
        for(int i=1;i<=k;i++){
            for(int j=m+(i*n-n)+1;j<=m+i*n;j++)road[j].vis=1;
            if(check()+c[i]>=lans)xuan[i]=1;
            for(int j=m+(i*n-n)+1;j<=m+i*n;j++)road[j].vis=0;
        }
        dfs(1,0);
        cout<<lans<<endl;
    }
    return 0;
}