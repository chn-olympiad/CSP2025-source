#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v,w;
    bool operator<(const Edge aa)const{
        return w>aa.w;
    }
}t;
int n,m,k,f[20005],cnt,sze[20005],c[105],ans;priority_queue<Edge>q;
bool fnd(int x){
    if(f[x]==x){
        return x;
    }
    return f[x]=fnd(f[x]);
}
void join(int x,int y){
    x=fnd(x);y=fnd(y);
    if(x==y){
        return;
    }
    /*if(sze[x]<sze[y]){
        int kk=x;x=y;y=kk;
    }*/
    f[y]=x;cnt--;//sze[x]+=sze[y];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);cnt=n;int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&t.u,&t.v,&t.w);
        q.push(t);
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    /*for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);t.u=0;t.v=n+i;t.w=c[i];q.push(t);f[n+i]=n+i;
        for(int j=1;j<=n;j++){
            scanf("%d",&t.w);
            t.u=n+i;t.v=j;
            q.push(t);
        }

    }*/
    while(cnt>0){
        t=q.top();q.pop();x=t.u;y=t.v;
        if(fnd(x)==fnd(y)){
            continue;
        }
        join(x,y);
        ans+=t.w;
    }
    printf("%d",ans);

    return 0;
}
