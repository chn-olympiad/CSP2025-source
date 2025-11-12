#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
const int N=5e4+5;
int n,rm,k;
struct node{
    int u,v,w;
}redge[M],edge[M];
bool cmp(node a,node b){
    return a.w<b.w;
}
int fa[M];
int fd(int u){
    if(fa[u]==u) return u;
    fa[u]=fd(fa[u]);
    return fa[u];
}
int a[105][N];
int p[105];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&rm,&k);
    for(int i=1;i<=rm;i++){
        scanf("%d %d %d",&redge[i].u,&redge[i].v,&redge[i].w);
    }
    bool flag1=true,flag2=false;
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(j==0){
                if(a[i][j]!=0) flag1=false;
            }
            else{
                if(a[i][j]==0){
                    p[i]=j;
                    flag2=true;
                }
            }
        }
    }
    if(flag1&&flag2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(i==p[j]) continue;
                rm++;
                redge[rm].u=i;
                redge[rm].v=p[j];
                redge[rm].w=a[j][i];
            }
        }
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        sort(redge+1,redge+1+rm,cmp);
        long long cnt=0;
        for(int i=1;i<=rm;i++){
            int fu=fd(redge[i].u);
            int fv=fd(redge[i].v);
            if(fu!=fv){

                fa[fu]=fv;
                cnt+=redge[i].w;
            }
        }
        printf("%lld",cnt);
        return 0;
    }
    long long ans=1e18;
    for(int s=0;s<=(1<<k)-1;s++){
        int m=rm;
        long long cnt=0;
        for(int i=1;i<=m;i++){
            edge[i]=redge[i];
        }
        int num=0;
        //printf("choose:\n");
        for(int i=0;i<k;i++){
            if((s&(1<<i))){
                num++;
                cnt+=a[i+1][0];
                //printf("%d\n",i+1);
                for(int j=1;j<=n;j++){
                    m++;
                    edge[m].u=n+num;
                    edge[m].v=j;
                    edge[m].w=a[i+1][j];
                }
            }
        }
        //printf("\n");
        for(int i=1;i<=n+num;i++){
            fa[i]=i;
        }
        sort(edge+1,edge+1+m,cmp);
        //for(int i=1;i<=m;i++){
        //    printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].w);
        //}
        for(int i=1;i<=m;i++){
            int fu=fd(edge[i].u);
            int fv=fd(edge[i].v);
            if(fu!=fv){

                fa[fu]=fv;
                cnt+=edge[i].w;
            }
        }
        //printf("%d\n",cnt);
        ans=min(ans,cnt);
    }
    printf("%lld",ans);
    return 0;
}
