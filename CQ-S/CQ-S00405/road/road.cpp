#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
struct node{
    int v;
    long long w;
};
struct node1{
    int u;
    long long w;
    bool operator<(const node1 &ano)const{
    	return ano.w<w;
	}
};
vector<node>road[10050];
bool f[10050]={0},ff[15]={0};
long long cost[15];
void tree(){
    priority_queue<node1>q;
    q.push({1,0});
    int cnt=0;
	while(q.size()){
        auto u=q.top();
        q.pop();
        if(f[u.u])continue;
        f[u.u]=1;
        ans+=u.w;
        if(u.u>=1&&u.u<=n){
        	cnt++;
        	if(cnt==n){
        		break;
			}
		}else{
			ff[u.u-n]=1;
		}
        for(auto i:road[u.u]){
            if(f[i.v]==0){
            	if(u.u>n&&ff[u.u-n]){
            		q.push({i.v,i.w-cost[u.u-n]});
				}
                else q.push({i.v,i.w});
            }
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
		long long w;
        cin>>u>>v>>w;
        road[u].push_back({v,w});
        road[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>cost[i];
        for(int j=1;j<=n;j++){
            long long uu;
            cin>>uu;
            road[n+i].push_back({j,uu+cost[i]});
            road[j].push_back({n+i,uu+cost[i]});
        }
    }
    tree();
    cout<<ans;
    return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/