#include<bits/stdc++.h>
using namespace std;
int u[1010],v[1010],w[1010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,h=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        h+=w[i];
    }
    cout<<h;
    return 0;
}
