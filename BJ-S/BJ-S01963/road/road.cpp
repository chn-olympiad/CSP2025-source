#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10,N=1e4+10;
int n,m,k;
bool vis[N];
struct node{
    int u,v,w;
}a[M*10];
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    }
    int tot=m;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=k;i++){
        int c,b[N];
        scanf("%d",&c);
        for(int j=1;j<=n;j++){
            scanf("%d",&b[j]);
            //printf("%d\n",c);

        }
        for(int j=1;j<=n;j++){
            for(int p=j+1;p<=n;p++){
                    a[++tot].u=j;
                    a[tot].v=p;
                    a[tot].w=c+b[j]+b[p];
                    //printf("%d %d %d %d\n",tot,c,b[j],b[p]);
            }
        }
    }
    //printf("%d\n",tot);
    sort(a+1,a+tot+1,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=tot;i++){
        //printf("%d\n%d %d %d\n",cnt,a[i].u,a[i].v,a[i].w);
        if(vis[a[i].u]&&vis[a[i].v]) continue;
        cnt++;
        vis[a[i].u]=1;
        vis[a[i].v]=1;
        ans+=a[i].w;
        if(cnt>=n)break;
    }
    printf("%d\n",ans);
    return 0;
}
