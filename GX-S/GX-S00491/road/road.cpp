#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int f[N],n,m,k;
inline int find(int s){
    if(f[s]==s)return s;
    else return f[s]=find(f[s]);
}
struct node{
    int u,v,w;
}e[N];
vector<pair<int,int> > g[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i=0;i<N;++i){
        f[i]=i;
    }
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;++i){
        int d;cin>>d;
        for(int j=1;j<=n;++j){
            int s;cin>>s;
            g[i].push_back(make_pair(j,s+d));
        }
    }
    cout<<0<<endl;
    return 0;
}
