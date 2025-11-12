#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int xuan[5005];
bool vis[5005];
int ans=0;
set<queue<int>> s;
void dfs(int x){
    if(x>=3){
        queue<int> q;
        int t[5005];
        for(int i=1;i<=x;i++){
            t[i]=xuan[i];
        }
        sort(t+1,t+x+1);
        for(int i=1;i<=x;i++){
            q.push(t[i]);
        }
        s.insert(q);
    }
    if(x>n){
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            xuan[x]=a[i];
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
            xuan[x]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    for(auto i : s){
        int maxx=-1;
        int he=0;
        while(!i.empty()){
            int u=i.front();
            i.pop();
            he+=u;
            maxx=max(maxx,u);
        }
        if(he>maxx*2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
