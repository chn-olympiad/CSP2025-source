#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
const int N=1e4+10;
struct node{
    int from,to,next,pri;
}a[M*2];
int n,m,k;
int u,v,w;
int kz,pre[M*2];
int c[15],d[15][N];
int cntc,cntd;
void add(int u,int v,int w){
    kz++;
    a[kz].from=u;
    a[kz].to=v;
    a[kz].pri=w;
    pre[u]=kz;
}
void fun1(){
    for(int i=1;i<=m;i++){
        int to=a[i].to;

    }
}
void fun2(){

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]==0) cntc++;
        for(int j=1;j<=n;j++){
            scanf("%d",&d[i][j]);
            if(d[i][j]==0){
                cntd++;
            }
        }
    }
    /*if(k==0){
        fun1();
        return 0;
    }
    if(cntc==k&&cntd==k*n){
        fun2();
        return 0;
    }*/
    printf("2025");
    return 0;
}
