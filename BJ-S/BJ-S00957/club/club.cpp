#include <bits/stdc++.h>

using namespace std;

int a[210][4];
bool vis1[1000];
bool vis2[1000];
bool vis3[1000];
int ans;
int T,n;
void dfs(int x,int a1,int a2,int a3){
  //  cout << x << ' ' << a1 << ' ' << a2 << ' ' << a3 << endl;
    if(x > n){
        int ret = 0;
        for(int i = 1; i <= n; i++){
            if(vis1[i]) ret += a[i][1];
            if(vis2[i]) ret += a[i][2];
            if(vis3[i]) ret += a[i][3];
        }
        ans = max(ans,ret);
        return ;
    }
    if(a1 < n/2){
    vis1[x] = 1;
    dfs(x+1,a1+1,a2,a3);
    }
    vis1[x] = 0;
    if(a2 < n/2){
    vis2[x] = 1;
    dfs(x+1,a1,a2+1,a3);
    }
    vis2[x] = 0;
    if(a3 < n/2){
    vis3[x] = 1;
    dfs(x+1,a1,a2,a3+1);
    }
    vis3[x] = 0;
}



int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
        cin >> T;
while(T--){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    dfs(1,0,0,0);
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        vis1[i] = 0;
        vis2[i] = 0;
        vis3[i] = 0;
    }
    ans = 0;
}
    return 0;
}
