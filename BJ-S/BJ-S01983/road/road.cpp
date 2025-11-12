#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
long long ans;
int a[N];
int f[N];
struct edge{
    int u,v,w;
};
bool operator < (edge x,edge y){
    return x.w > y.w;
}
priority_queue<edge,vector<edge>,less<edge> > p;
int find(int x){
    if(f[x]==x) return x;
    else return find(f[x]);
}
void add(int x,int y){
    f[x]=find(x);
    f[f[x]]=y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int Max=0;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        int ui,vi,wi;
        scanf("%d%d%d",&ui,&vi,&wi);
        Max=max(Max,wi);
        edge t;
        t.u=ui;
        t.v=vi;
        t.w=wi;
        p.push(t);
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            scanf("%d",&a[j]);
        }
        for(int j=1;j<n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[0]+a[j]+a[k]<Max){
                    edge t;
                    t.u=j;
                    t.v=k;
                    t.w=a[0]+a[j]+a[k];
                    p.push(t);
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        while(find(p.top().u)==find(p.top().v)) p.pop();
        ans+=p.top().w;
        add(p.top().u,p.top().v);
        p.pop();
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}