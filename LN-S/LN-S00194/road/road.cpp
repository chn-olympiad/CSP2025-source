#include<bits//stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll ii,n;
};
ll n,m,k,x,y,z,r[5050][5050],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    node u;
    cin>>n>>m>>k;
    for(int i=1;i<=5000;i++){
        for(int j=1;j<=5000;j++){
            r[i][j]=2000000000;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        r[x][y]=z;
        r[y][x]=z;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(r[i][j]&&r[j][k]) r[i][k]=max(r[i][k],r[i][j]+r[j][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans+=r[1][i];
    }
    cout<<ans;
    return 0;
}
