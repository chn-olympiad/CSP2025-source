#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5050];
int ans;
queue<int> q;
void dfs(int step,int sum,int k){
    if(step==n){
        if(k>=3){
            ans++;
        }
        return;
    }
    dfs(step+1,sum,k);
    dfs(step+1,sum+a[step],k+1);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,0,0);
    cout<<ans;
    return 0;
}

