#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct _{int v,w;};
int n,m,k,b[11],f[11],d[10011];long long c;
vector<_>a[10011];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0,u,v,w;i<m;i++){scanf("%d%d%d",&u,&v,&w);a[u].push_back({v,w});a[v].push_back({u,w});}
    for(int i=n+1,p;i<n+1+k;i++){scanf("%d",&p);b[i-n]=p;for(int j=1,w;j<=n;j++){scanf("%d ",&w);a[j].push_back({i,w});}}
    for(int i=1,mn,x,y;i<=n;i++){mn=2E9;
        if(d[i]==1)continue;
        for(int j=0;j<a[i].size()-k;j++)if(mn>a[i][j].w)mn=min(mn,a[i][j].w),x=j;
        for(int j=a[i].size()-k;j<a[i].size();j++)if(mn>a[i][j].w+f[j-n]?0:b[j-n])mn=min(mn,a[i][j].w+f[j-n]?0:b[j-n]),f[j-n]=1,x=j;
        for(int j=0;j<a[a[i][x].v].size();j++)if(a[a[i][x].v][j].v==i){y=j;break;}
        a[i][x].w=a[a[i][x].v][y].w=2E9,d[i]=d[a[i][x].v]=1,c+=mn;
    }cout<<c<<endl;
    return 0;
}//g++ -O2 -std=c++14 -static road.cpp -o b