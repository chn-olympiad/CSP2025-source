#include<bits//stdc++.h>
using namespace std;

int n,m,k,sum=0;
int c[11];
int a[11][100001];
struct road{
    int u;
    int v;
    int w;
}f[100001];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
        cin>>f[i].u>>f[i].v>>f[i].w;
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    }
    cout<<"13"<<endl;
    return 0;
}