#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
struct Q{
    int v,c;
};
vector<Q> e[500005];
int mp[105][10005];
int fa[100005];
bool book[100005],sum[105];
int find(int s){
    if(s==fa[s]){
        return fa[s];
    }
    return fa[s]=find(fa[s]);
}
void bfs(){
    queue<int> q;
    q.push(1);
    book[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto t:e[u]){
            int v=t.v,c=t.c;
            if(find(v)==find(u)||book[v]){
                continue;
            }
            bool f;
            for(int i=1;i<=k;i++){
                if(!sum[i]&&mp[i][u+1]+mp[i][v+1]+mp[i][1]<=c){
                    fa[v]=u;
                    ans+=mp[i][u+1]+mp[i][v+1]+mp[i][1];
                    sum[i]=1;
                    q.push(v);
                    book[v]=1;
                    f=1;
                    break;
                }
                if(sum[i]&&mp[i][u+1]+mp[i][v+1]<=c){
                    cout<<1<<endl;
                    fa[v]=u;
                    ans+=mp[i][u+1]+mp[i][v+1];
                    q.push(v);
                    book[v]=1;
                    f=1;
                    break;
                }
            }
            if(!f){
                fa[v]=u;
                ans+=c;
                q.push(v);
                book[v]=1;
            }
            cout<<ans<<" "<<u<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        e[x].push_back({y,c});
        e[y].push_back({x,c});
    }
    bool check=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>mp[i][j];
            if(mp[i][j]!=0){
                check=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    if(check==0){
        cout<<0<<endl;
        return 0;
    }
    bfs();
    cout<<ans<<endl;
    return 0;
}
