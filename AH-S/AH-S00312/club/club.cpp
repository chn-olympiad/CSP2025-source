#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][3],ans;
inline void dfs(long long i,long long x,long long y,long long z,long long s){
    if(x>n/2||y>n/2||z>n/2){
        return;
    }
    if(i==n){
        ans=max(ans,s);
        return;
    }
    dfs(i+1,x+1,y,z,s+a[i][0]);
    dfs(i+1,x,y+1,z,s+a[i][1]);
    dfs(i+1,x,y,z+1,s+a[i][2]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(long long i=0;i<n;++i)cin>>a[i][0]>>a[i][1]>>a[i][2];
        ans=0;
        dfs(0,0,0,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
