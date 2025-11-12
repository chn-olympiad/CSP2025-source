#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans;
bool vis[5005];
void dfs(int t,int sum,int mx){
    if(t>n){
        if(sum>2*mx){
            ans++;
        }
        return ;
    }
    dfs(t+1,sum+a[t],max(mx,a[t]));
    dfs(t+1,sum,mx);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    dfs(1,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
