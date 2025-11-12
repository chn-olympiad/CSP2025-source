#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
using namespace std;
int n,m,k;
struct edge{
    int e,c;
};
vector<edge> ed[10001];
bitset<10001> vis;
bool operator<(const edge& a,const edge& b){
    return a.c>b.c;
}
int fc[10],fx[10];
vector<int> f[10];
int krim(){
    int cost=0;
    vis.reset();
    priority_queue<edge> pq;
    vis[1]=1;
    for(edge i:ed[1]){
        pq.push(i);
    }

    while(!pq.empty()){
        edge top=pq.top();
        if(vis[top.e]){
            pq.pop();
        }else{
            cost+=top.c;
            vis[top.e]=1;
            for(edge i:ed[top.e]){
                pq.push(i);
            }
            if(top.e){
                pq.push({0,fx[top.e]});
            }else{
                for(int i=1;i<=n;i++){
                    pq.push({i,fx[i]});
                    //cout << i <<' '<< fx[i] << endl;
                }
            }
            //cout << top.e << ' ' << top.c << endl;
        }
    }

    return cost;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int s,e,c;
        cin >> s >> e >> c;
        ed[s].push_back({e,c});
        ed[e].push_back({s,c});
    }
    for(int i=0;i<k;i++){
            cin >> fc[i];
        for(int j=0;j<n;j++){
            int t;
            cin >> t;
            f[i].push_back(t);
        }
    }


    for(int j=1;j<=n;j++){
        fx[j]=0x3fffffff;
    }
    int ans=krim()-0x3fffffff;
    //cout << krim()-0x3fffffff << endl;

    for(int i=1;i<(1<<k);i++){

        int fixc=0;
        int t=0;
        while((1<<t)<=i){
            if((1<<t)&i){
                fixc+=fc[t];
                for(int j=1;j<=n;j++){
                    fx[j]=min(fx[j],f[t][j]);
                }
            }
            t++;
        }
        ans=min(ans,krim()+fixc);
        //cout << krim() << ' ' << fixc << endl;
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}














