#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll ans;
int u[1000005],v[1000005],w[1000005];
int cit[10005];
int k,c[11],a[11][10005];
bool vis[10005];
struct road{
    int to,w,nxt;
}e[1000005];
int num;

road que[1000005];
int siz;
void up(int x){
    while(x>1&&que[x].w<que[x/2].w){
        swap(que[x],que[x/2]);
        x=x/2;
    }
}
void push(road x){
    que[++siz]=x;
    up(siz);
}
road top(){
    return que[1];
}
void down(int x){
    int son;
    if(que[x*2].w<=que[x*2+1].w) son=x*2;
    else son=x*2+1;
    if(que[x].w>que[son].w){
       swap(e[x],e[son]);
        down(son);
    }
}
void pop(){
    que[1]=que[siz];
    siz--;
    down(1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        e[++num].nxt=cit[u[i]];
        e[num].to=v[i];
        e[num].w=w[i];cit[u[i]]=num;
        e[++num].nxt=cit[v[i]];
        e[num].to=u[i];
        e[num].w=w[i];cit[v[i]]=num;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(road i=e[cit[1]];i.to!=0;i=e[i.nxt]){
        push(i);
        //cout<<i.to<<' ';
    }
    //cout<<endl;
    vis[1]=1;
    road r;
    while(siz!=0){
        do{
            if(siz=0){
                cout<<ans<<endl;
                return 0;
            }
            r=top();
            pop();
        }while(vis[r.to]);
        if(r.to==0) break;
        //cout<<r.to<<' '<<r.w<<endl;
        vis[r.to]=1;
        ans+=r.w;
        for(road i=e[cit[r.to]];i.to!=0;i=e[i.nxt]){
            if(i.to!=0&&!vis[i.to])
            push(i);
            //cout<<i.to<<' ';
        }
        //cout<<top().w<<endl;
        /*for(int i=1;i<=siz;i++)
            cout<<que[i].w<<' ';
        cout<<endl;*/
    }
    cout<<ans<<endl;
    return 0;
}
