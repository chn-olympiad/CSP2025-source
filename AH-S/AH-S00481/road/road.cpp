#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct nnde{
    int u,v,w;
};
nnde a[10010];
int dd;
vector<int> g[10010];
bool cmp(nnde a,nnde b){
    return a.w<b.w;
}
long long cost;
map<bool,map<int,int>>d;
int c;
queue<nnde> q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[i].u=u;
        a[i].v=v;
        a[i].w=w;
    }
    dd=m;
    for(int i=0;i<k;i++){
        int u,v,w;
        cin>>u;
        for(int j=0;j<n;j++){
            v=j+1;
            cin>>w;
            a[dd].u=u;
            a[dd].v=j+1;
            a[dd].w=w;
            dd++;
        }
    }

    sort(a,a+dd,cmp);
    for(int i=0;i<dd;i++){
        int op=a[i].u;
        int ed=a[i].v;
        int cc=a[i].w;
        if(d[op][ed]==0||d[ed][op]==0){
            cost+=cc;
            d[op][ed]=1;
            d[ed][op]=1;
            for(int j=0;j<g[op].size();j++){
                int now=g[op][j];
                d[now][ed]=1;
                d[ed][now]=1;
                g[now].push_back(ed);
                g[ed].push_back(now);
            }
            for(int j=0;j<g[ed].size();j++){
                int now=g[ed][j];
                d[now][op]=1;
                d[op][now]=1;
                g[now].push_back(op);
                g[op].push_back(now);
            }
            g[op].push_back(ed);
            g[ed].push_back(op);
        }
    }
    cout<<cost;
    return 0;
}
