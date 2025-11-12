#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int maxn=1e4+5;
const int maxm=1e6+5;
int n,m,k;
int tw,twf[maxn];
struct nd{
    int v,w;
}ct;
vector<nd>rd[maxn];
struct qd{
    int v,w;
    friend bool operator<(qd a,qd b){
        return a.w>b.w;
    }
}qt;
priority_queue<qd>pq;

//bing cha ji START
int fa[maxn];
int find(int a){
    if(a==fa[a]){
        return a;
    }
    return fa[a]=find(fa[a]);
}
void join(int a,int b){
    int ffa=find(a);
    int ffb=find(b);
    fa[ffb]=ffa;

}
//bing cha ji END

int T(int u){
    int cnt=0;
    int out=0;
    for(int i=0;i<rd[u].size();i++){
        qt.v=rd[u][i].v;
        qt.w=rd[u][i].w;
        pq.push(qt);
    }
    for(;;){
        if(cnt==n-1){
            break;
        }
        int v=pq.top().v;
        int lg=pq.top().w;
        join(u,v);
        pq.pop();
//        cout<<v<<endl;
//        cout<<lg<<endl;
        out+=lg;
        cnt++;
        u=v;
        for(int i=0;i<rd[u].size();i++){
            if(find(rd[u][i].v)==find(u)){
                continue;
            }
            qt.v=rd[u][i].v;
            qt.w=rd[u][i].w;
            pq.push(qt);
        }
    }
    return out;
}


signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;

//bing cha ji Init
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }

    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ct.v=v;ct.w=w;
        rd[u].push_back(ct);
        ct.v=u;
        rd[v].push_back(ct);
    }
    for(int i=1;i<=k;i++){
        cin>>tw;
        for(int j=1;j<=n;j++){
            cin>>twf[j];
        }
        for(int r=1;r<=n;r++){
            for(int s=1;s<=n;s++){
                if(r==s){
                    continue;
                }
                ct.v=s;ct.w=twf[r]+twf[s]+tw;

                rd[r].push_back(ct);
            }
        }
    }
    cout<<T(1)<<endl;/*
    for(int i=1;i<=n;i++)
        cout<<rd[i].size()<<endl;
    cout<<endl;
    for(int i=0;i<rd[1].size();i++){
        
        cout<<rd[1][i].v<<" "<<rd[1][i].w<<endl;
    }*/
    return 0;
}
