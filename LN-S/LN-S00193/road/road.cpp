#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c[N],w[N];
int a[N][N];
int n,m,k,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
       int a,b;
       cin>>a>>b>>w[i];
    }
    for(int i=1;i<=k;i++){
       cin>>c[i];
       for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    for(int i=1;i<=m;i++) ans+=w[i];
    cout<<ans<<endl;
    return 0;
}