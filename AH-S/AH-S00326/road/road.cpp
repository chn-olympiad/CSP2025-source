#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[100005],p[100005],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b>>c[i];
    }
    for(int i=1;i<=k;i++){
        cin>>p[i];
        int l;
        for(int j=1;j<=n;j++) cin>>k;
    }
    sort(c+1,c+1+m);
    for(int i=1;i<=n-1;i++) ans+=c[i];
    cout<<ans;
    return 0;
}
