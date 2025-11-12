#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],tmp[100005],f[10005];
long long ans;
struct node{
    int u;
    int v;
    int w;
    friend bool operator<(struct node x,struct node y){
        return x.w>y.w;
    }
};
priority_queue<struct node>q;
int read(){
    int x=0;
    char c=getchar();
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int get(int x){
    if(f[x]==x){
        return x;
    }
    f[x]=get(f[x]);
    return f[x];
}
void merge(int u,int v){
    f[get(v)]=f[get(u)];
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++){
        struct node t;
        t.u=read();
        t.v=read();
        t.w=read();
        f[t.u]=t.u;
        f[t.v]=t.v;
        q.push(t);
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        int goal=0;
        for(int j=1;j<=n;j++){
            tmp[j]=read();
            if(tmp[j]==0){
                goal=j;
            }
        }
        for(int j=1;j<=n;j++){
            if(j!=goal){
                q.push({goal,j,tmp[j]});
            }
        }
    }
    int cnt=1;
    while(cnt<=n-1){
        struct node x=q.top();
        q.pop();
        if(get(x.u)==get(x.v)){
            continue;
        }
        merge(x.u,x.v);
        cnt++;
        ans+=x.w;
    }
    printf("%lld\n",ans);
    return 0;
}
