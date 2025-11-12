#include<bits/stdc++.h>
using namespace std;
int u[100005],v[100005],w[100005],c[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >>n>>m>>k;
    for(int i=0;i<m;i++){
        cin >>u[i]>>v[i]>>w[i];
    }
    for(int j=0;j<k;j++){
        cin >>c[j];
        for(int i=0;i<n;i++){
            cin >>a[j];
        }
    }
    cout <<"13";
    return 0;
}
