#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x,y,w;
};
Node a[1000005];
int in;
int q[10005];
bool cmp(Node x,Node y){
    return x.w<y.w;
}
int getf(int x){
    if(q[x]==x){
        return x;
    }
    q[x]=getf(q[x]);
    return q[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        Node t;
        t.x=u;
        t.y=v;
        t.w=w;
        a[++in]=t;
        t.x=v;
        t.y=u;
        a[++in]=t;
    }
    sort(a+1,a+1+in,cmp);
    for(int i=1;i<=n;i++){
        q[i]=i;
    }
    int x,y;
    for(int i=1;i<=k;i++){
        scanf("%d",&x);
        for(int j=1;j<=n;j++){
            scanf("%d",&y);
        }
    }
    long long sum=0;
    for(int j=1;j<=in;j++){
        if(getf(q[ a[j].x ]) != getf(q[ a[j].y ])){
            sum+=a[j].w;
            q[ a[j].y ]=getf( q[ a[j].x ] );
        }
    }
    cout<<sum;
    return 0;
}
