//t2simple
#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+5,maxk=12;
int n,m,k,c[10005][15];
struct edge{
    int u;
    int v;
    int w;
};
vector<edge>e;
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            for(int w=0;w<=n;w++){
                
            }
        }
        int ans=0
        for(int j=1;j<=n;j++){
            if(i&(1<<(j-1))){
                ans+=c[j][0];
                for(int w=1;w<=n;w++){
                    v[j+n].push_back({w,c[j][w]});
                    v[w].push_back({j.c[j][w]});
                }
            }
        }
        for(int j=1;j<=n+k;j++){
            v[j].earse(0,v[j].size())
        }
    }
    return 0;
}