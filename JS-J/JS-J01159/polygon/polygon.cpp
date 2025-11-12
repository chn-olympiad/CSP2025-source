#include<bits/stdc++.h>
using namespace std;
const int INF = 998244353, N = 1e6 + 10;
int x,cnt = 0;
int a[N],b[N];
bool vis[N];
void dfs(int num){
    if(num > 3){
        int ans = 0,maxx = 0;
        for(int i = 0;i<num;i++){
            ans+=b[i];
            maxx = max(maxx,b[i]);
        }
        if(ans > maxx * 2)cnt++;
    }
    for(int i = 0;i<x;i++){
        if(vis[i] == false && a[i] >= b[num-1]){
            vis[i] = true;
            b[num] = a[i];
            dfs(num+1);
            vis[i] = false;
            b[num] = 0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> x;
    for(int i = 0;i<x;i++){
        cin >> a[i];
    }
    dfs(0);
    cout << cnt%INF;
    return 0;
}
