#include <bits/stdc++.h>

using namespace std;

int n,m,k,a[1000005][3],ans=0;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++)ans+=a[i][3];
    cout<<ans;
    return 0;
}
