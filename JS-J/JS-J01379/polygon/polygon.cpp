#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 998244353;
int n,a[6000];
ll ans;
bool usd[6000];
void dfs(int num,int rest,int mx,int mn) {
    if (num >= 3 && rest < 0) ans++;
    for (int i = mn;i <= mx;i++) {
        if (usd[i] == false) {
            usd[i] = true;
            dfs(num+1,rest-a[i],mx,i+1);
            usd[i] = false;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(usd,sizeof(usd),false);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 3;i <= n;i++) {
        dfs(1,a[i],i-1,1);
    }
    cout << ans%M;
    return 0;
}
