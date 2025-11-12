#include<bits/stdc++.h>
using namespace std;
int ut[10005],vt[10005];
int main()
{
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    int n,m,k;
    int u[1000005],v[1000005],w[1000005];
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
        ut[u[i]]++;
        vt[v[i]]++;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin>>a[i];
        }

    }
    return 0;
}
