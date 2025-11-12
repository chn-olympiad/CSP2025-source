#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
    int v,w;
};
vector<node> v[N];
int c[15];
int dis[N],f[N];
int n,m,k;
void qqq(){
    queue<int> q;
    q.push(1);
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    int ans=0;
    int cnt=0;
    while(q.size()>0){
        int t=q.front();
        //cout<<t<<" ";
        q.pop();
        int s=-1,nu=0;
        for(int i=0;i<v[t].size();i++){
            int a=v[t][i].v;
            int b=v[t][i].w;
            if(s==-1&&f[a]==0) s=b,nu=a;
            if(s>b&&f[a]==0) s=b,nu=a;
        }
        if(s!=-1){
            f[nu]=1;
            dis[nu]=v[t][nu].w;
        }
        if(s==-1) break;
        q.push(nu);
        for(int i=0;i<v[t].size();i++){
            int a=v[t][i].v;
            int b=v[t][i].w;
            if(f[a]==1) continue;
            dis[a]=min(dis[a],b);
        }
    }
    for(int i=1;i<=n;i++){
        ans+=dis[i];
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
        //cout<<x<<y<<z<<endl;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int qq;
            cin>>qq;
            v[j].push_back({i,qq});
            v[i].push_back({j,qq});
        }
    }
    qqq();

    return 0;
}
