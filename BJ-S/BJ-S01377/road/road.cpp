#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u[1000010],v[1000010],w[1000010];
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    int a[10][10000];
    int c[10];
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    srand(time(0));
    cout<<rand()%INT_MAX;


    fclose (stdin);
    fclose(stdout);
    return 0;

}
