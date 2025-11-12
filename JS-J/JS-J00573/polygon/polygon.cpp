#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool h[5005];
int ans = 0;
void dfs(int dk = 1){
    if(dk == n + 1){
        int sum = 0,nmax = 0;
        for(int i = 1;i <= n;i++){
            sum += h[i] * a[i];
            nmax = max(nmax,h[i] * a[i]);
        }
        if(sum > 2 * nmax) ans++;
        return;
    }
    for(int i = 0;i <= 1;i++){
        h[dk] = i;
        dfs(dk+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    dfs();
    cout<<ans;
    return 0;
}
