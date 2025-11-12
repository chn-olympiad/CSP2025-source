#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=998*244*353;
int a[N],ans,n;
void dfs(int step,int cnt,int mx){
    if(step==n+1){
        if(cnt>mx*2)ans++;
        return;
    }
    dfs(step+1,cnt+a[step],a[step]);
    dfs(step+1,cnt,mx);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,a[1]);
    cout<<ans%mod;
return 0;
}
