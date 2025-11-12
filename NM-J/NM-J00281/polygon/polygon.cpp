#include<bits/stdc++.h>
using namespace std;
int n, x, u, da, he;
long long ans;
int k[1000010];
int a[1000010];
void dfs(int x, int y){
      if(x > n){
        return;
      }
      if(y > n){
        return;
      }
      k[x] = a[y];
      if(x >= 3){
        he = 0;
        da = -1;
        for(int i = 1;i <= x;i++){
            he += k[i];
            da = max(da,k[i]);
        }
        if(he > da*2){
            ans++;
        }
      }
      dfs(x+1, y+1);
      if(x != 1)
      dfs(x, y+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(0,0);
    cout << ans;
    return 0;
}
