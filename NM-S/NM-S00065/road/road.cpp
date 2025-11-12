#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,ans;
int w[N][N],c[N][N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i][3];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i][n];
    }
    for(int i=1;i<=m;i++){
            if(w[i][1]<w[i][2]&&w[i][1]<w[i][3]){
                ans+=w[i][1];
            }
            if(w[i][2]<w[i][1]&&w[i][2]<w[i][3]){
                ans+=w[i][2];
            }
            if(w[i][3]<w[i][2]&&w[i][3]<w[i][1]){
                ans+=w[i][1];
            }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j]<c[i][j+1])
                ans+=c[i][j];
        }
    }
    cout<<ans;
}
