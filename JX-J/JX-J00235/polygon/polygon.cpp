#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long ans,n,a[5005];
void dfs(long long pos,long long gs,long long res,long long maxn){
    if(pos>n){
        ans+=(res>maxn*2&&gs>=3);
        ans%=mod;
        return;
    }
    dfs(pos+1,gs,res,maxn);
    dfs(pos+1,gs+1,res+a[pos],max(maxn,a[pos]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1,0,0,0);
    cout << ans << '\n';
}
