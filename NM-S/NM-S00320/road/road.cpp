#include<bits/stdc++.h>
using namespace std;

//
struct node1{
    int u,v,w;
}road[10002];

struct node2{
    int c,a[10001];
}country[11];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>road[i].u>>road[i].v>>road[i].w;
    }
    for(int j=1;j<=k;j++){
        cin>>country[j].c;
        for(int cs=1;cs<=n;cs++){
            cin>>country[i].a[cs];
        }
    }

}
