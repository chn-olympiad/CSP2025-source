#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,c=0;
    cin>>n>>m>>k;
    int u[m],v[m],w[m];
    for(int i=0;i<m;m++){
        cin>>u[i]>>v[i]>>w[i];
        c+=w[i];
    }
    cout<<c;
    return 0;
}
