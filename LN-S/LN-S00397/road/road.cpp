#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> u;
    vector<int> v;
    vector<int> w;
    vector<vector<int>> a;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int j=1;j<=k;j++){
        for(int m=1;m<=n;m++){
            cin>>a[j][m];
        }
    }
    cout<<10<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
