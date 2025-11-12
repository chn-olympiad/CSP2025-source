#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
long long n,m,k,fa[N+1000],c[100],a[100][N];
struct ssss{
    int u,v,w;
}e[2*M+15*M];
//struct sss{
 //   int nxt,to,v,fr;
//}e[2*M];
//int hd[2*M],cnt,
long long ans;
bool cmp(ssss x,ssss y){
    return x.w<y.w;
}
//void add(int x,int y,int z){
  //  e[++cnt].nxt=hd[x];
    //e[cnt].fr=x;
  //  e[cnt].to=y;
 //   e[cnt].v=z;
  //  hd[x]=cnt;
//}
int getz(int x){
    if(x==fa[x]){
        return x;
    }
    return getz(fa[x]);
}
void mergez(int x,int y){
    fa[y]=getz(x);
}
bool checkz(int x,int y){
    if(getz(x)==getz(y)){
        return false;
    }
    return true;
}
void zxs(){
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(checkz(e[i].u,e[i].v)){
            mergez(e[i].u,e[i].v);
            ans+=e[i].w;
        }
    }
}void zxs(){
    sort(e+1,e+1+m+k*n,cmp);
    for(int i=1;i<=m;i++){
        if(checkz(e[i].u,e[i].v)){
            mergez(e[i].u,e[i].v);
            ans+=e[i].w;
        }
    }
}
int faaa=0;
int humble=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
     //   int u,v,w;
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
      //  add(u,v,w);
        //add(u,v,w);
    }
    for(int i=1;i<=m;i++){
        fa[i]=i;
    }
    faaa=k*n;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(c[i]==0&&a[i][j]==0){
                humble++;
            }
        }
    }
    if(k==0){
        zxs();
        cout<<ans;
    }else if(humble==faaa){
        cout<<0;
    }
    return 0;
}
