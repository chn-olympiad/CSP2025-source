#include <bits/stdc++.h>
using namespace std;
int n,m,k;
#define MAXN 10505
#define MAXM 1000005
#define MAXNK 100005
#define MAXK 10
struct edge{
    int u,v,w;
    bool operator < (const edge &a)const{
        return w > a.w;
    }
};
vector <edge> E[MAXN];
int iset[MAXN];
int rec[MAXK];
int sumk[MAXK];
priority_queue <edge> q;
map <pair<int,int>, int> mp;
int ans = 0;
int find(int x){
    if(x == iset[x]){
        return x;
    }
    iset[x] = find(iset[x]);
    return iset[x];
}
void combine(int x, int y){
    int xx = find(x);
    int yy = find(y);
    if(xx != yy){
        iset[x] = y;
    }
}
void kruskal(int ccc){
    int cnt = ccc;
    while(cnt > 1){
        edge ed = q.top();
        q.pop();
        int tx = ed.u, ty = ed.v, di = ed.w;
        if(find(tx) != find(ty)){
                //cout<<tx<<"  "<<ty<<"  "<<di<<endl;
            combine(tx,ty);
            cnt--;
            ans += di;
            //record how many edges this node connect
            if(tx > n){
                rec[tx-n] ++;
                sumk[tx-n]+=di;
            }
            if(ty > n){
                rec[ty-n] ++;
                sumk[ty-n]+=di;
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i <= m; i++){
        int u1,v1,w1;
        cin>>u1>>v1>>w1;
        E[u1].push_back((edge){u1,v1,w1});
        E[v1].push_back((edge){v1,u1,w1});
        q.push((edge){u1,v1,w1});
        q.push((edge){v1,u1,w1});
    }
    for(int i = 0; i <= n+k; i++){
        iset[i] = i;
    }
    for(int i = 1; i <= k; i++){
        // build edge from i to n+i which cost w1
        // build edge from n+i to k(1 <= k <= n) which cost mp[make_pair(i,j)];
        int w1;
        cin>>w1;
        E[i].push_back((edge){0,n+i,w1});
        E[n+i].push_back((edge){n+i,0,w1});
        q.push((edge){0,n+i,w1});
        q.push((edge){n+i,0,w1});
        combine(i,n+i);
        ans += w1;
        rec[i]++;
        sumk[i] += w1;
        combine(0,n+i);
        ans += w1;
        for(int j = 1; j <= n; j++){
            cin>>w1;
            E[n+i].push_back((edge){n+i,j,w1});
            E[n+i].push_back((edge){j,n+i,w1});
            q.push((edge){n+i,j,w1});
            q.push((edge){j,n+i,w1});
        }
    }
    q.push((edge){0,1,0});
    q.push((edge){1,0,0});
    kruskal(n+1);
    //check if there is any virtual node abandon
    for(int i = 1; i <= k; i++){
        if(rec[i] == 1){
            ans -= sumk[i];
        }
    }
    cout<<ans;
}
