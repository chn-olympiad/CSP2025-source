#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+27;
const int maxk=17;

int n,m,k;
long long ans=-1;
long long c[maxk];
bool can_visit[maxk];

struct edge{
    int v;
    long long w;
    bool operator < (const edge x)const{
        return w>x.w;
    }
};

vector<edge> e[maxn];

bool vis[maxn];
long long solve(int sum){
    memset(vis,false,sizeof(vis));
    long long res=0;
    int cnt=0;
    priority_queue<edge> pq;
    cnt++;
    vis[1] = true;
    for(int i=0;i<e[1].size();i++){
        pq.push(e[1][i]);
    }
    while(!pq.empty()){
        edge now=pq.top();
        pq.pop();
        if(vis[now.v] == true)
            continue;
        if(now.v > n  &&  can_visit[now.v-n] == false)
            continue;
        //cout<<"[log] "<<sum<<" "<<now.v<<endl;
        cnt++;
        res += now.w;
        if(cnt == sum)
            break;
        vis[now.v] = true;
        for(int i=0;i<e[now.v].size();i++){
            int v=e[now.v][i].v;
            if(vis[v] == true)
                continue;
            if(v > n  &&  can_visit[v-n] == false)
                continue;
            pq.push(e[now.v][i]);
        }
    }
    //cout<<"[cnt] "<<cnt<<endl;
    return res;
}

void dfs(int ind,int sum,long long cost){
    if(ind > k){
        long long res=solve(sum)+cost;
        /*
        for(int i=1;i<=k;i++)
            cout<<can_visit[i]<<" ";
        cout<<endl;
        cout<<res<<endl;
        */
        if(ans == -1)
            ans = res;
        else
            ans = min(ans,res);
        return;
    }
    can_visit[ind] = false;
    dfs(ind+1,sum,cost);
    can_visit[ind] = true;
    dfs(ind+1,sum+1,cost+c[ind]);
    return;
}

void dfs1(){
    memset(can_visit,false,sizeof(can_visit));
    for(int i=1;i<=k;i++){
        for(int j=0;j<e[n+i].size();j++){
            if(e[n+i][j].w == 0){
                int u=e[n+i][j].v;
                for(int h=0;h<e[n+i].size();h++){
                    int v=e[n+i][h].v,w=e[n+i][h].w;
                    e[u].push_back(edge{v,w});
                    e[v].push_back(edge{u,w});
                }
                break;
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(auto it:e[i]){
            cout<<it.w<<" ";
        }
        cout<<endl;
    }
    */
    ans = solve(n);
    return;
}

int main(){
    //freopen("input.txt","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool flag1=true;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        e[u].push_back(edge{v,w});
        e[v].push_back(edge{u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i] != 0)
            flag1 = false;
        for(int j=1;j<=n;j++){
            long long l;
            cin>>l;
            e[n+i].push_back(edge{j,l});
            e[j].push_back(edge{n+i,l});
        }
    }
/*
    for(int i=1;i<=n+k;i++){
        for(auto it:e[i]){
            cout<<it.v<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
*/
    if(flag1)
        dfs1();
    else
        dfs(1,n,0);
    cout<<ans<<endl;
    return 0;
}
