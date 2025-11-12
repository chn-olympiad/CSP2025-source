#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5050;
const int MOD = 998244353;
int n,ans;
int len[MAXN];
void dfs(int now,int left,int sum){
    if(left==0){
        int pos=lower_bound(len+1,len+1+n,sum)-len;
        int left=pos-now;
        ans=(ans+left)%MOD;
        return;
    }
    if(now==n+1){
        return;
    }
    dfs(now+1,left,sum);
    if(left>0){
        dfs(now+1,left-1,sum+len[now]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i];
    }
    sort(len+1,len+1+n);
    for(int i=3;i<=n;i++){
        dfs(1,i-1,0);
    }
    cout<<ans<<endl;
    return 0;
}
