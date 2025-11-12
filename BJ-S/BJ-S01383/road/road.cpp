#include<bits/stdc++.h>
using namespace std;
struct T{
    int v,w;
};
int n,m,k,u,v,w,sum;
vector<T> a[10005];
bool vis[10005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        cout<<i;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    queue<int> q;
    for(int i=2;i<=n;i++){
        q.push(i);
    }
    vis[1]=1;
    while(!q.empty()){
        int d=q.front();
        q.pop();
            int minn=0x3f3f3f3f;
            for(int j=1;j<a[d].size();j++){
                if(vis[a[d][j].v]){
                    minn=min(minn,a[d][j].w);
                }
            }
            if(minn!=0x3f3f3f3f){
                sum+=minn;
                vis[d]=1;
            }
            else q.push(d);
        }

    cout<<sum;
}
