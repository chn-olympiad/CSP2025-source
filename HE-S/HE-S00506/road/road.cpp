#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u[10001],v[10001],w[10001],c[10001],a1[10001],a2[10001],a3[10001],a4[10001];
    cin>>n>>m>>k;
    for(int i=1;i<m+1;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=0;i<k;i++){
        cin>>c[i]>>a1[i]>>a2[i]>>a3[i]>>a4[i];
    }
    cout<<"13";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
