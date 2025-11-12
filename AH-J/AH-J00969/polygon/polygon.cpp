#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5000+5;
LL n,a[N],ans,man;
void dfs(LL cur,LL sum,LL maxn){
    if(cur==n+1){
        if(sum>2*maxn) ans++;
        return ;
    }
    dfs(cur+1,sum+a[cur],max(maxn,a[cur]));
    dfs(cur+1,sum,maxn);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        man=max(man,a[i]);
    }
    if(man==1){
        cout<<n-2;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
