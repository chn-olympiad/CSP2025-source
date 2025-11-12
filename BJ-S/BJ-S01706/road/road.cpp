#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int a[11][10005];
int fa[10050],n,m,k,x1,x2,x3;
int cost[15]={};
struct sd{
    int x,y,z;
};
vector<sd> node[10025];
bool operator< (sd x1,sd x2){return x1.z<x2.z;}
sd temp[1000091];
int get(int x){
    if(fa[x]==x)return x;
    fa[x]=get(fa[x]);
    return fa[x];
}int mer(int x,int y){
    fa[get(x)]=get(y);
}
int krus(int op){
    int c=0;
    memset(temp,0,sizeof(temp));
    int ans=0;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    bool o[11]={};int u,u1,u2;
    while(op){
        u=op&-op;u1=0;c++;
        u2=u;
        while(u!=0){
            u/=2;u1++;
        }
        ans+=cost[u1];
        o[u1]=1;op-=u2;
    }
    int tot=0;
    for(int i=1;i<=k;i++){
        if(o[i]==1){
            for(int j=0;node[n+i][j].y!=0;j++){
                temp[++tot].x=node[n+i][j].x;
                temp[tot].y=node[n+i][j].y;
                temp[tot].z=node[n+i][j].z;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;node[i][j].y!=0;j++){
                temp[++tot].x=node[i][j].x;
                temp[tot].y=node[i][j].y;
                temp[tot].z=node[i][j].z;
            }
    }
    sort(temp+1,temp+tot+1);
    int xx=0;
    for(int i=1;i<=tot;i++){
        int x1=temp[i].x,y1=temp[i].y,z1=temp[i].z;
        if(get(y1)!=get(x1)){mer(y1,x1);ans+=z1;xx++;}
    }
    bool tag=1;
    for(int i=1;i<n;i++){
        if(get(i)!=get(i+1))tag=0;
    }
    if(tag)return ans;
    else return 199999999;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int op;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x1,&x2,&x3);
        sd df,dg;
        df.x=x1,dg.x=x2;
        df.y=x2;df.z=x3;
        dg.y=x1;dg.z=x3;
        node[x1].push_back(df);
        node[x2].push_back(dg);
    }for(int i=1;i<=k;i++){
        scanf("%d",&cost[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            sd adf,adg;
            adf.x=n+i;adg.x=j;
            adf.y=j;adf.z=a[i][j];
            adg.y=n+i;adg.z=a[i][j];
            node[i+n].push_back(adf);
            node[j].push_back(adg);
        }
    }
    int ans=199999999;
    for(op=0;op<(1<<k);op++){
        int yy=krus(op);
        if(yy<ans)ans=yy;
    }printf("%d",ans);
}
