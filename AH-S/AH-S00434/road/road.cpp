#include <bits/stdc++.h>
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
using namespace std;
const int dd=2e4+5;
int fa[dd],siz[dd];int n,m,k;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void Union(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    if(siz[fx]>siz[fy])swap(fx,fy);
    fa[fx]=fy;siz[fy]+=siz[fx];
}
struct edge{
    int from,to,v;
};
auto cmp=[](edge&a,edge&b){return a.v>b.v;};
priority_queue<edge,vector<edge>,decltype(cmp)>q(cmp);
int c[15];int a[15][dd];
int kruscal(){
    int ans=0,cnt=1;
    while(cnt!=n+k){
        edge now=q.top();q.pop();
        if(find(now.from)==find(now.to))continue;
        ans+=now.v;Union(now.from,now.to);cnt++;
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),w=read();
        q.push({x,y,w});
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            a[i][j]=read();
            q.push({i+n,j,a[i][j]});
        }
    }
    for(int i=1;i<=n+k;i++){
        siz[i]=1;fa[i]=i;
    }
    printf("%lld\n",kruscal());

    fclose(stdin);
    fclose(stdout);
    return 0;
}
