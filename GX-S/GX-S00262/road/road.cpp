#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct ed{
    long long to,w;
};
vector<ed>eds[20000];
int cnt;
bool o[20000];
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >q;
long long prim(int x){
    q.push({0,1});
    cnt=0;

    long long ans=0;
    while(cnt!=x){
        long long w=q.top().first;
        int u=q.top().second;
        q.pop();
        if(!o[u]){
            o[u]=true;
            ans+=w;
            cnt++;
        }
        for(int i=0;i<eds[u].size();i++){
            int v=eds[u][i].to;
            long long w1=eds[u][i].w;
            if(!o[v]){
                q.push({w1,v});
            }

        }
    }return ans;
}
int minans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        eds[x].push_back({y,w});
        eds[y].push_back({x,w});
    }
    minans=prim(n);
    int a=n;
    int c[20]={0,0},b=0;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int y;
            cin>>y;
        }
    }
    cout<<minans;
    return 0;
}
