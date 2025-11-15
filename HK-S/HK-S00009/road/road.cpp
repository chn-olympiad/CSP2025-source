#include  <bits/stdc++.h>
using namespace std;
ifstream in("road.in");
ofstream out("road.out");
struct st{
    int u,v,w;
};
using ll = long long;
int n,m,k;
vector<st> path;
vector<int> c;
vector<vector<int>> a;
long long ff(int hi){
    priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, greater<pair<ll, pair<int,int>>>> pq;

    ll cost=0;
    vector<int> rank(n);
    vector<int> used(k,0);
    for(int i=0;i<n;i++)    rank[i]=i;
    for(int i=0;i<k;i++){
        if(hi&(1ll<<i)){
            cost+=c[i];
            rank.push_back(rank.back()+1);
        
            for(int j=0;j<n;j++){
                pq.push({a[i][j], {j,rank.back()}});
            }
        }
    }
    //cout<<cost<<'\n';
    for(int i=0;i<m;i++){
        pq.push({path[i].w, {path[i].u, path[i].v}});
    }
    int rl=rank.size();
    while(!pq.empty()){
        auto p=pq.top();
        //cout<<p.first<<' '<<p.second.first<<' '<<p.second.second<<' '<<rank[p.second.first]<<' '<<rank[p.second.second]<<' ';
        if(rank[p.second.first]!=rank[p.second.second]){
            //cout<<'u';
            cost+=p.first;

            if(p.second.second>=n&&used[p.second.second-n]==0){
                used[p.second.second-n]=p.first;
                //cout<<'h'<<endl;
            }else if(p.second.second>=n){
                used[p.second.second-n]=-1;
            }
            
            int lll=rank[p.second.first];
            for(int i=0;i<rl;i++){
                if(rank[i]==lll)    rank[i]=rank[p.second.second];
            }
        }
        //cout<<endl;

        pq.pop();
    }

    for(int i=0;i<used.size();i++){
       if(used[i]>0)    cost-=used[i]+c[i];
    }


    //cout<<cost<<'\n';
    return cost;
}
int main(){
    in.tie(nullptr);

    in>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        in>>u>>v>>w;

        path.push_back({u-1,v-1,w});
    }

    c.resize(k+1);
    a.assign(k+1,vector<int>(n));

    for(int i=0;i<k;i++){
        in>>c[i];
        for(int j=0;j<n;j++)    in>>a[i][j];
    }

    long long hi=(1ll<<k)-1;
    long long ans=1e18;
    //cout<<"st\n";
    for(int i=0;i<=hi;i++){
        ans=min(ans,ff(i));
    }

    out<<ans<<'\n';

    return 0;
}