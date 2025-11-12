#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
const int Mod = 998244353;
int n;
int res = 0;
int a[N];
void dfs(int i,int mx,int sum) {
    if(i > n) {
        if(2 * mx < sum)res++;
        res %= Mod;
        return;
    }
    dfs(i + 1,mx,sum);
    dfs(i + 1,max(mx,a[i]),sum + a[i]);
    return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dfs(1,0,0);
    cout << res;
    return 0;
}
