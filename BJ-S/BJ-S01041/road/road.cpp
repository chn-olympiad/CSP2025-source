#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
struct Node{
    int en,val;
};
vector<Node>Map[N];

bool jadge[N];
int ans=0x3f3f3f3f;

void dfs(int start,int cnt,int sum){
    if(cnt>n)return ;
    if(cnt==n){
        ans=min(ans,sum);
    }
    int t=start;
    for(int i=0;i<Map[t].size();i++){
        if(jadge[Map[t][i].en])continue;
        jadge[Map[t][i].en]=1;
        dfs(Map[t][i].en,cnt+1,sum+Map[t][i].val);
        jadge[Map[t][i].en]=0;
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        Map[u].push_back({v,w});
        Map[v].push_back({u,w});
    }
    
    for(int i=1;i<=n;i++){
        jadge[i]=1;
        dfs(i,0,0);
        for(int j=1;j<=m;j++)jadge[i]=0;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
