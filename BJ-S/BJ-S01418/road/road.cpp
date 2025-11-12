#include<bits/stdc++.h>
using namespace std;
const int M=1e9+5;
int mp[10015][10015],gz[11];// 第n+1至n+10个城市表示村镇
struct RD{
    int a,b,m;
}rd[2000005];
int cnt,lts=1;
long long ans;
bool cmp(RD a,RD b){
    return a.m<b.m;
}
void newb(int a,int b,int m){
    mp[a][b]=min(mp[a][b],m);
    mp[b][a]=min(mp[b][a],m);
}
void tjb(int a,int b,int m){
    rd[cnt].a=a;
    rd[cnt].b=b;
    rd[cnt++].m=m;
}
int pre[10005];
int fd(int p){
    if(pre[p]==p) return p;
    return pre[p]=fd(pre[p]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int xza=1;
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int u,v,w;
    for(int i=1;i<=n+10;i++){
        for(int j=1;j<=n+10;j++){
            mp[i][j]=M;
            if(i==j) mp[i][j]=0;
        }
    }
    for(int i=1;i<=n+10;i++){
        pre[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        newb(u,v,w);
    }
    int zc[n],ld=0;
    for(int i=1;i<=k;i++){
        scanf("%d",&gz[i]);
        if(gz[i]) xza=0;
        for(int j=1;j<=n;j++){
           scanf("%d",&zc[j]);
           if(!zc[j]) ld=j;
        }
        for(int j=1;j<=n;j++){
            if(ld!=j) newb(ld,j,zc[j]);
        }
    }
    if(k==0||xza==1){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(mp[i][j]<M&&mp[i][j]>0) tjb(i,j,mp[i][j]);
            }
        }
        sort(rd,rd+cnt,cmp);
        for(int i=0;i<cnt;i++){
            u=rd[i].a;
            v=rd[i].b;
            w=rd[i].m;
            if(fd(u)==fd(v)) continue;
            ans+=w;
            pre[fd(v)]=fd(u);
            lts++;
            if(lts==n) break;
        }
        printf("%lld",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
