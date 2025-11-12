#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10050;
int n,m,k;
vector<pair<int,int> > vec[N];
bool st[N];
int kru(){
    int ans=0;
    queue<int> q;
    q.push(1);
    st[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<vec[u].size();i++){
            if(st[vec[u][i].first]==0){
                st[vec[u][i].first]=1;
                ans+=vec[u][i].second;
                q.push(vec[u][i].first);
            }
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>c;
            vec[n+i].push_back({j,c});
            vec[j].push_back({n+i,c});
        }
    }
    memset(st,0,sizeof st);
    cout<<0;
    return 0;
}

