#include<bits/stdc++.h>
using namespace std;

int main(){#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> cmap[10005];
vector<int> wealth[10005];
int a[15][10005];
queue<int> q;
int ind[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ans+=w;
        cmap[u].push_back(v);
        cmap[v].push_back(u);
        wealth[u].push_back(w);
        ind[u]++;
        ind[v]++;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(ind[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<cmap[x].size();i++){
            ind[cmap[x][i]]--;
            if(ind[cmap[x][i]]==1){
                q.push(cmap[x][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ind[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<wealth[x].size();i++){
            ind[wealth[x][i]]--;
            if(ind[wealth[x][i]]==1){
                q.push(wealth[x][i]);
            }
        }
    }
    cout<<w;
}


