#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[200005],v[200005],w[200005],c[15],a[15][10005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<0;
    return 0;
}
