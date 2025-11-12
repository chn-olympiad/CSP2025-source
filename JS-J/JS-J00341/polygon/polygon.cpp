#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=988244353;
int n,a[N],ans;
void dfs(int step,int maxn,int cnt){
    if(step==n+1){
        if(cnt>maxn*2) ans++;
        return;
    }

    dfs(step+1,maxn,cnt);
    maxn=max(maxn,a[step]);
    dfs(step+1,maxn,cnt+a[step]);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans%mod;
    return 0;
}
