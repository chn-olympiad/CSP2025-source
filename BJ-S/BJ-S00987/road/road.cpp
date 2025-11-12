#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> > s[10005];
int c[10005];
bool isfine(bool flag[10005][2]){
    for(int i=1;i<=n;i++){
        if(!flag[n][0])return false;
    }
    return true;
}
long long DFS(int a,bool flag[10005][2]={},int ls=0){
    if(isfine(flag))return 0;
    flag[a][0]=true;
    long long ans=INT_MAX;
    for(int i=0;i<s[a].size();i++){
        if(flag[s[a][i].first][0]){
            //ans=min(ans,DFS(s[a][i].first,flag,a));
            flag[a][1]=true;
            continue;
        }
        ans=min(ans,DFS(s[a][i].first,flag,a)+s[a][i].second);
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        s[x].push_back({y,z});
        s[y].push_back({x,z});
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
    }
    cout<<DFS(1)<<endl;
    return 0;
}