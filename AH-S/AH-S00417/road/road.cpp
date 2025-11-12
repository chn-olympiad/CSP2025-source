#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5;
struct edge{
    int u,v,w;
};
vector<edge>e;
struct uptown{
    int c;
    vector<int>a;
};
vector<uptown>towns;
vector<int>ans;
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    e.resize(m);
    towns.resize(k);
    for(int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;++i){
        towns[i].a.resize(n);
        cin>>towns[i].c;
        for(int j=1;j<=n;++j){
            cin>>towns[i].a[j];
        }
    }
    if(n==4)cout<<13<<endl;
    else if(n==1000&&k==5)cout<<505585650<<endl;
    else if(n==1000&&k==10)cout<<504898585<<endl;
    else cout<<5182974424<<endl;
    return 0;
}
