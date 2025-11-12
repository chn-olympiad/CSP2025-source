#include<bits/stdc++.h>
using namespace std;//60 bufen
const int N=1e4+10,M=1e6+10;
int h[N],val[10*N+M],to[10*N+M],ne[10*N+M],idxp=1;
void add(int a,int b,int d){val[++idxp]=d;to[idxp]=b;ne[idxp]=h[a];h[a]=idxp;}
int aj[N],cj[20];
bool vis[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        int ui,vi,wi;
        scanf("%d%d%d",&ui,&vi,&wi);
        add(ui,vi,wi);add(vi,ui,wi);
    }
    for(int i=0;i<k;i++){
        scanf("%d",&cj[i+1]);
        if(cj[i]){
            //bai lan
            continue;
        }
        int cntz=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&aj[j]);
            if(!aj[j])cntz=j;
        }
        if(!cntz){
            //bai lan
            continue;
        }
        for(int j=1;j<=n;j++){
            if(j==cntz)continue;
            add(cntz,j,aj[j]);add(j,cntz,aj[j]);
        }
    }
    int last=n;
    priority_queue<pair<int,int> > que;
    vis[1]=1;que.push({0,1});
    last--;
    int ans=0;
    while(last){
        int now=que.top().second;
        if(vis[now])continue;
        vis[now]=1;
        ans+=-que.top().first;
        que.pop();
        for(int nowp=h[now];nowp>0;nowp=ne[nowp]){
            que.push({-val[nowp],to[nowp]});
        }
        last--;
    }
    printf("%d",ans);
    return 0;
}/*

ui vi 
wi
cj+aji



*/
