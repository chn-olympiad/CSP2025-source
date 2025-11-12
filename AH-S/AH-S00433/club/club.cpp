#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3];
int n,ans,k;
void dfs(int sum,int x,int y,int z,int t){
    if(t>n){
        ans=max(ans,sum);
        return;
    }
    if(x+1<=k)dfs(sum+a[t][0],x+1,y,z,t+1);
    if(y+1<=k)dfs(sum+a[t][1],x,y+1,z,t+1);
    if(z+1<=k)dfs(sum+a[t][2],x,y,z+1,t+1);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--){
        cin>>n;
        k=n/2;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        dfs(0,0,0,0,1);
        cout<<ans<<"\n";
    }
    return 0;
}
