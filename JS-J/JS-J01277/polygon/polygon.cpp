#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
#define ll long long
#define P 998244353
int a[maxn];
int n;
ll ans=0;
void dfs(int now,ll sum,int mx,int m){
    if(now==n+1&&(sum<=mx*2||m<3))return;
    if(now==n+1){
        ans++;ans%=P;
        return;
    }
    dfs(now+1,sum,mx,m);
    dfs(now+1,sum+a[now],max(mx,a[now]),m+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0,-1,0);
    cout<<ans;
    return 0;
}
