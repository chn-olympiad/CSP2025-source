#include <iostream>
#include <queue>
using namespace std;
struct eg_f{
    int to,nxt,len;
}eg[1000006];
int dis[10004];
bool vst[10004];
int head[10004];
int cntedge=0;
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void addedge(int frm,int to,int len){
    eg[++cntedge].to=to;
    eg[cntedge].nxt=head[frm];
    eg[cntedge].len=len;
    head[frm]=cntedge;
}
void prim(){
    long long ans=0;
    while(!q.empty()){
        vst[q.top().second]=1;
        ans+=dis[q.top().second];
        int egsrl=head[q.top().second];
        while(eg[egsrl].to){
            if(!vst[eg[egsrl].to]&&eg[egsrl].len<dis[eg[egsrl].to]){
                dis[eg[egsrl].to]=eg[egsrl].len;
                q.push(make_pair(dis[eg[egsrl].to],eg[egsrl].to));
            }
            egsrl=eg[egsrl].nxt;
        }
        while(!q.empty()&&vst[q.top().second]) q.pop();
    }
    cout<<ans<<endl;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k; cin>>n>>m>>k;
    if(k){cout<<0; return 0;}
    while(m--){
        int frm,to,len; cin>>frm>>to>>len;
        addedge(frm,to,len);
        addedge(to,frm,len);
    }
    fill(dis,dis+10004,0x7fffffff);
    dis[1]=0;
    q.push(make_pair(0,1));
    prim();
    return 0;
}

