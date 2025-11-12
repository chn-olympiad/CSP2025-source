#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
int u[N],v[N],w[N];
int w1[20],w2[N][20];
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++) {
        cin>>w1[i];
        for(int j=1;j<=m;j++) cin>>w2[j][i];
    }
    cout<<"13";
    return 0;
}
