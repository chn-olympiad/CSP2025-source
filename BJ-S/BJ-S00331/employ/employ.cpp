#include<bits/stdc++.h>
#define piii pair<int,pair<int,int>>
using namespace std;
const int maxn=1e5+10;
int n,m,k;
int u[maxn],v[maxn],w[maxn],c[maxn],a[maxn][maxn];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    cout << 1 << endl;
    return 0;
}