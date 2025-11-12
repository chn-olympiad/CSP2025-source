#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
struct Node{
    ll x,y,z;
}a[200010];
ll maxn;
void dfs(ll i,ll ans1,ll ans2,ll ans3,ll cnt){
    if(i==n+1){
        maxn=max(maxn,cnt);
        return;
    }
    if(ans1<n/2) dfs(i+1,ans1+1,ans2,ans3,cnt+a[i].x);
    if(ans2<n/2) dfs(i+1,ans1,ans2+1,ans3,cnt+a[i].y);
    if(ans3<n/2) dfs(i+1,ans1,ans2,ans3+1,cnt+a[i].z);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=0;
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        dfs(1,0,0,0,0);
        cout<<maxn<<endl;
    }
    return 0;
}
