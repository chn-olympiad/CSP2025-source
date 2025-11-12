#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5010];
int n;
int cnt;
int dep;
int ans;
void dfs(int last,int depth,int sum){
    if(depth==dep){
        if(sum>2*a[last])ans++;
        ans%=998244353;
        return ;
    }
    for(int i=last+1;i<n;i++){
        dfs(i,depth+1,sum+a[i]);
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)cnt++;
    }
    if(cnt==n){
        cout<<n-2;
        return 0;
    }
    sort(a,a+n);
    int whi=3;
    for(int i=3;i<=n;i++){
        dep=i;
        dfs(-1,0,0);
    }
    cout<<ans;
    return 0;
}


