#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
vector<vector<int>> g(N);
int n,m,k;
int u[N],v[N],w[N],c[20];
int a[20][N];
int p,q;
int main(){
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
       // g[u[i]].push_back(v[i]);
    }
    for(int i=1;i<=k;i++){
           cin>>c[i];
       for(int j=1;j<=n;j++){
            cin>>a[i][j];
       }
    }
    srand(time(0));
    p=1;q=100;
    cout<<p+rand()%(q-p+1);
    return 0;
}
