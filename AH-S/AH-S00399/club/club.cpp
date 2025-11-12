#include<bits/stdc++.h>
using namespace std;
int vis[4];
int a[100005][4];
int n;
long long ans;
void dfs(long long sum,int step){
    if(step>n){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++){
        if(vis[i]<n/2){
            vis[i]++;
            dfs(sum+a[step][i],step+1);
            vis[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        memset(vis,0,sizeof vis);
        dfs(0,1);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
