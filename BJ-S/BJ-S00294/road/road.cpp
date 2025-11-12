#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+7;
const int MAXM=1e6+7;
const int MAXK=11;
vector <pair<int,int> > edge[MAXN];
int cost[MAXK];
int in[MAXK];
int f[MAXK][MAXN];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > ff[MAXK];
int minval=1e15+7;
int medd;
int mk;
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
bool visit[MAXN];
int dist[MAXN];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back(make_pair(v,w));
        edge[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++){
            cin>>f[i][j];
            ff[i].push(make_pair(f[i][j],j));
        }
    }
    memset(dist,0x3f,sizeof(dist));
    memset(in,0x3f,sizeof(in));
    dist[1]=0;
    int ans=0;
    q.push(make_pair(dist[1],1));
    while(!q.empty()){
        if(minval<=q.top().first){
            ff[mk].pop();
            ans+=minval;
            visit[medd]=true;
            dist[medd]=minval;
            in[mk]=0;
            cost[mk]=0;
            for(int i=0;i<edge[medd].size();i++){
                pair<int,int> now=edge[medd][i];
                if(dist[now.first]>now.second&&visit[now.first]==false){
                    dist[now.first]=now.second;
                    q.push(make_pair(dist[now.first],now.first));
                }
            }
            for(int i=1;i<=k;i++){
                in[i]=min(in[i],f[i][medd]);
            }
            minval=1e15+7;
            for(int i=1;i<=k;i++){
                while(!ff[i].empty()&&visit[ff[i].top().second]==true){
                    ff[i].pop();
                }
                if(ff[i].empty()) continue;
                int val=in[i]+cost[i]+ff[i].top().first;
                int edd=ff[i].top().second;
                if(minval>val){
                    minval=val;
                    medd=edd;
                    mk=i;
                }
            }
            continue;
        }
        pair<int,int> p=q.top();
        q.pop();
        if(dist[p.second]<p.first||visit[p.second]==true){
            continue;
        }
        ans+=p.first;
        visit[p.second]=true;
        for(int i=0;i<edge[p.second].size();i++){
            pair<int,int> now=edge[p.second][i];
            if(dist[now.first]>now.second&&visit[now.first]==false){
                dist[now.first]=now.second;
                q.push(make_pair(dist[now.first],now.first));
            }
        }
        for(int i=1;i<=k;i++){
            in[i]=min(in[i],f[i][p.second]);
        }
        minval=1e15+7;
        for(int i=1;i<=k;i++){
            while(!ff[i].empty()&&visit[ff[i].top().second]==true){
                ff[i].pop();
            }
            if(ff[i].empty()) continue;
            int val=in[i]+cost[i]+ff[i].top().first;
            int edd=ff[i].top().second;
            if(minval>val){
                minval=val;
                medd=edd;
                mk=i;
            }
        }
    }
    cout<<ans;
}
