#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[10005];
vector<int> w[10005];
int c[15];
int d[15][10005];
struct node{
    int sz;
    int id;
    friend bool operator <(node X,node Y){
        return X.sz<Y.sz;
    }
    friend bool operator >(node X,node Y){
        return X.sz>Y.sz;
    }
};
int vis[10005];
int main(){
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(y);
        v[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    priority_queue<node,vector<node>,greater<node> > pq;
    pq.push({0,1});
    long long ans=0;
    while(!pq.empty()){
        node nx=pq.top();
        pq.pop();
        if(vis[nx.id]){
            continue;
        }
        vis[nx.id]=1;
        ans+=nx.sz;
        int si=v[nx.id].size();
        for(int i=0;i<si;i++){
            int p=v[nx.id][i];
            if(!vis[p]){
                pq.push({w[nx.id][i],p});
            }
        }
    }
    if(k==0){
        cout<<ans;
        exit(0);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }
    int tar=1<<k;
    for(int i=1;i<=tar;i++){
        vector<int> v1[10005];
        vector<int> w1[10005];
        for(int j=1;j<=n;j++){
            v1[j]=v[j],w1[j]=w[j];
        }
        long long sum=0;
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1==1){
                sum+=c[j];
                for(int l=1;l<=n;l++){
                    for(int r=l+1;r<=n;r++){
                        long long dis=d[j][l]+d[j][r];
                        v1[l].push_back(r);
                        v1[r].push_back(l);
                        w1[l].push_back(dis);
                        w1[r].push_back(dis);
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            vis[j]=0;
        }
        priority_queue<node,vector<node>,greater<node> > pq;
        pq.push({0,1});
        while(!pq.empty()){
            node nx=pq.top();
            pq.pop();
            if(vis[nx.id]){
                continue;
            }
            vis[nx.id]=1;
            sum+=nx.sz;
            int si=v1[nx.id].size();
            for(int i=0;i<si;i++){
                int p=v1[nx.id][i];
                if(!vis[p]){
                    pq.push({w1[nx.id][i],p});
                }
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
