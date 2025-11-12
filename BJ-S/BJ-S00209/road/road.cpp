#include <bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
struct node{
    int v;
    long long w;
    bool operator<(const node &a)const{
        return a.w<w;
    }
};
int n,m,k;
priority_queue<node> pq;
priority_queue<node> pq2;
priority_queue<node> q[12];
vector<node> e[M];
int vis[N];
int a[N][12];
int r[N][12];
int c[12],f[12];
int cnt;
bool ff;
long long ans;
int main()
{
    //llong !!
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        f[j]=1;
        for(int i=1;i<=n;i++){
            int z;
            cin>>z;
            q[j].push({i,z});
            a[i][j]=z;
        }
    }
    vis[1]=1;
    cnt=1;
    for(int i=0;i<e[1].size();i++){
        pq.push({e[1][i].v,e[1][i].w});
    }
    for(int i=1;i<=k;i++){
        if(q[i].top().v==1) q[i].pop();
        if(q[i].empty()) continue;
        int t=q[i].top().v;
        int tw=a[1][i]+c[i]+q[i].top().w;
        pq2.push({t*11+i,tw});
    }
    while(cnt<n){
        int t2;
        long long w2=4000000001;
        while(!pq.empty() && vis[pq.top().v]) pq.pop();
        int t1=pq.top().v;
        int w1=pq.top().w;
        //if(pq2.empty()) ff=true;
        while(!pq2.empty() && (vis[pq2.top().v/11] || f[pq2.top().v%11]==0)) pq2.pop();
        if(!pq2.empty())
        {
            t2=pq2.top().v/11;
            w2=pq2.top().w;
        }
        cnt++;//i?
        if(w1<=w2){
            ans+=w1;
            pq.pop();
            //cout<<t1<<" "<<ans<<'\n';
            vis[t1]=1;
            for(int i=0;i<e[t1].size();i++){
                if(vis[e[t1][i].v]) continue;
                pq.push({e[t1][i].v,e[t1][i].w});
            }
            for(int i=1;i<=k;i++){
                if(f[i]==0) continue;
                while(!q[i].empty() && vis[q[i].top().v])  q[i].pop();
                if(q[i].empty()) continue;
                int t=q[i].top().v;
                int tw=a[t1][i]+c[i]+q[i].top().w;
                pq2.push({t*11+i,tw});
            }
        }else{
            int k2=pq2.top().v%11;
            //cout<<k2<<'\n';
            ans+=w2;
            //cout<<t2<<" "<<k2<<" "<<ans<<'\n';
            f[k2]=0;
            vis[t2]=1;
            pq2.pop();
            while(!q[k2].empty()){
                int vv=q[k2].top().v,ww=q[k2].top().w;
                q[k2].pop();
                if(vis[vv]) continue;
                pq.push({vv,ww});
            }
            for(int i=0;i<e[t2].size();i++){
                if(vis[e[t2][i].v]) continue;
                pq.push({e[t2][i].v,e[t2][i].w});
            }
            for(int i=1;i<=k;i++){
                if(f[i]==0) continue;
                while(!q[i].empty() && vis[q[i].top().v])  q[i].pop();
                if(q[i].empty()) continue;
                int t=q[i].top().v;
                int tw=a[t2][i]+c[i]+q[i].top().w;
                pq2.push({t*11+i,tw});
            }
        }
    }
    cout<<ans;
    return 0;
}
