#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+5,MOD = 998244353;
ll a[N],n,cnt=0,ans[N]={0},t[N]={1,1};
void dfs(ll k,ll sum,ll maxn){
    if(k>3){
        if(sum>2*maxn)
            cnt = cnt + 1 % MOD;
    }
    for(ll i = ans[k-1]+1;i<=n;i++){
        ans[k] = i;
        dfs(k+1,sum+a[i],max(maxn,a[i]));
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,-1);
    cout<<cnt;
    return 0;
}
