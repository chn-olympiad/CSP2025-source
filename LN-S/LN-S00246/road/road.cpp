#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,num,u1[1000001],v1[1000001],w1[1000001],c[11],a[11][10001],bo[10001] = {0};
int dfs(int num){
    for (int i = 0;i < )
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 0;i < m;i++){
        cin >> u1[i] >> v1[i] >> w1[i];
    }
    for (int j = 0;j < k;j++){
        cin >> c[j];
        for (int p = 0;p < n;p++){
            cin >> a[j][p];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
