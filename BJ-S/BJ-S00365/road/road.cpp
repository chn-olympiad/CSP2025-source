#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct node{
    int x, y ,c;
}a[N];
int n, m, k, f[15][1005],ans = 0;
int main(){
    freopen("road.in","r",stdin); 
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].c;
        ans+=a[i].c;
    }
    for(int i = 1;i<=k;i++){
        for(int j = 0;j<=n;j++){
            cin>>f[i][j];
        }
    }
    cout<<ans;
    return 0;
}
