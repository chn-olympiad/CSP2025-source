#include <bits/stdc++.h>
using namespace std;
struct Node{
    int u,v,w;
}a[1000005];
bool cmp(Node x,Node y){
    return x.w<y.w;
}
int fa[1000005],vis[1000005],c[1000005],b[20][10005];
int find(int x){
    if(x==fa[x]){
    return x;}
    return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m,k,ans=0;
    cin>>n>>m>>k;//k=0;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(a+1,a+1+m,cmp);int cnt=0;
    if(k==0){
    for(int i=1;i<=m;i++){
        int fx=find(a[i].u),fy=find(a[i].v);
        if(fx==fy){
        continue;}
        fa[fx]=fy;
        cnt++;
        ans+=a[i].w;
        if(cnt==n-1){
            cout<<ans;return 0;
        }
    }
    }int md=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        vis[c[i]]=1;
       // if(c[i]!=0) md=1;//cout<<111;
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
            //if(b[i][j]!=0) md=1;//cout<<111;
        }
    }//cout<<111;
    if(md==0){
        for(int i=1;i<=m;i++){
            if(vis[a[i].u]==1||vis[a[i].v]==1){
                a[i].w=0;
            }
        }sort(a+1,a+1+m,cmp);
        for(int i=1;i<=m;i++){
        int fx=find(a[i].u),fy=find(a[i].v);
        if(fx==fy){
        continue;}
        fa[fx]=fy;
        cnt++;
        ans+=a[i].w;
        if(cnt==n-1){
            cout<<ans;exit(0);
        }
        }
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
