#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll M = 998244353;
ll ans = 0;
vector<int> lis;
int n;
void dfs(int it, int num, ll sm, int mx){
    if(it == n + 1){
        if(sm > mx * 2){ans++; ans %= M;}
        return;
    }
    it++;
    dfs(it, num + 1, sm + lis[it], max(mx, lis[it]));
    dfs(it, num, sm, mx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d", &n);
    lis.resize(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &lis[i]);
    }
    dfs(0, 1, 0, 0);
    cout << ans % M;
    return 0;
}




