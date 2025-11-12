#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10100;
int id[N];
int fa(int u){
    if(id[u]==u)return u;
    return id[u]=fa(id[u]);
}
multiset<pair<int,pair<int,int>>> s;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        s.insert({w,{u,v}});
    }
    for(int i=1;i<=n;i++)id[i]=i;
    int cnt=0;
    int sum=0;
    while(cnt!=n&&!s.empty()){
        pair<int,pair<int,int>> p=*s.begin();
        int u=p.second.first;
        int v=p.second.second;
        int w=p.first;
        s.erase(s.begin());
        if(fa(u)==fa(v))continue;
        sum+=w;
        id[u]=v;
        cnt++;
    }
    cout<<sum<<endl;
    return 0;
}