#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10000],b[10000],c[10000],d[10000],e[10000],ans=0,ans2;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        ans+=c[i];
    }
    for(int i=1;i<=k;i++){
        cin>>d[i];
        ans2=d[i];
        for(int j=1;j<=n;j++){
            cin>>e[i];
            ans2+=e[i];
        }
        ans=min(ans,ans2);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
