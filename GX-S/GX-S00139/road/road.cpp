#include<bits/stdc++.h>
using namespace std;



int cnt,head[0x3f3f3f];
int dis[0x3f3f3f];
int n,m,k;
bool vis[0x3f3f3f];
bool vis2[0x3f3f3f];
map<int,vector<int>>s;

struct edge{
    int to,w,next;
}a[0x3f3f3f];

struct node{
    int pos,dis;
    bool operator<(const node &a)const{
        return dis<a.dis;
    }
};


void add(int x,int y,int z){
    cnt++;
    a[cnt].to=y;
    a[cnt].w=z;
    a[cnt].next=head[x];
    head[x]=cnt;
}

void di(int s){
    priority_queue <node>q;
    q.push(node{s,0});
    for(int i=0;i<=n;i++)dis[i]=0x3f3f3;
    dis[s]=0;
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        if(vis[tmp.pos])continue;
        vis[tmp.pos]=1;
        for(int i=head[tmp.pos];i;i=a[i].next){
            if(dis[a[i].to]>dis[tmp.pos]+a[i].w){
                vis2[tmp.pos]=1;
                dis[a[i].to]=dis[tmp.pos]+a[i].w;
                q.push(node{a[i].to,dis[a[i].to]});
            }
        }
    }
}

int main(){

    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        add(x,y,z);
        add(y,z,x);
    }
    for(int i=0;i<k;i++){
        int c;cin>>c;
        for(int j=1;j<=n;j++){
        }
        for(int j=1;j<=n;j++){
            int co;cin>>co;
        }
    }
    int ma=0;
    di(1);
    for(int j=1;j<=n;j++)ma=max(ma,dis[j]);
    cout<<ma;

    return 0;
}
