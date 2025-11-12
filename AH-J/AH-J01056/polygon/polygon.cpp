#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=5010,M=998244353;
int n;
int a[N];
int cnt;
void dfs(int t,int sum,int mx,int co){
    if(t>n){
        if(co>=3 && sum>mx*2) cnt++;

        cnt%=M;
        return;
    }
    int g=max(mx,a[t]);
    dfs(t+1,sum+a[t],g,co+1);
    dfs(t+1,sum,mx,co);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<cnt;
    return 0;
}
