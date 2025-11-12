#include <iostream>
using namespace std;

int n,m,k;
int dp[10005][10005];


int main(){
//    freopen("road.in","r",stdin);
//    freopen("road.out","r",stdout);
    cin>>n>>m>>k;
    memset
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        dp[x][y] = z;
        dp[y][x] = z;
    }
    for (int i=0;i<=k;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
    }
    cout<<0;
    return 0;
}
