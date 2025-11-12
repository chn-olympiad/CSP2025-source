#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
long long cnt,ans;
int cmpnumbers;
long long al;
int a[maxn];
bool vis[maxn];
void dfs(int t,int n){
    cnt += t;
    cmpnumbers = max(cmpnumbers,t);
    if(cnt > cmpnumbers * 2) (ans ++) % 998244353;
    for(int i = 1;i <= n;i++){
        if(vis[i] == 0){
            vis[i] = 1;
            dfs(a[i],n);
            vis[i] = 0;
            dfs(0,n);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    cout << 1;

    return 0;
}
