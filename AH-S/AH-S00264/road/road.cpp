#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,a[100005],c[105],cw[15][100005];
int fa[100005];
long long ans;
struct edge{
    int u,v,w;
}e[2000005];
int aaaa;
int fo0od(int x){
    if(fa[x]==x) return x;
    return fa[x]=fo0od(fa[x]);
}
void merge(int op1,int op2){
    //cout<<"merge"<<op1<<' '<<op2<<endl;
    int fd1=fo0od(op1);
    int fd2=fo0od(op2);
    fa[fd1]=fd2;
}
bool cmp(edge A,edge B){
    return A.w<B.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i=1;i<=100002;i++) fa[i]=i;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        
    }
    for(int i=1;i<=k;i++){
        scanf("%d",c+i);
        for(int j=1;j<=n;j++){
            
            scanf("%d",&cw[i][j]);
        }
    }
    stable_sort(e+1,e+1+m,cmp);
    int ks=n;
    for(int i=1;i<=m;i++){
        if(fa[e[i].u]==fa[e[i].v]) continue;
        //printf("%d %d\n",e[i].u,e[i].v);
        ks--;
        //printf("%d %d %d\n",e[i].u,e[i].v,ks);
        merge(e[i].u,e[i].v);
        ans+=e[i].w;
        //printf("%lld\n",ans);
        if(ks==1) break;
    }
    cout<<ans<<endl;
    return 0;
}
//Ren5Jie4Di4Ling5%
/*
5 7 0
1 5 2
1 4 3
1 2 4
2 3 5
2 4 6
4 5 7
3 4 8

*/
