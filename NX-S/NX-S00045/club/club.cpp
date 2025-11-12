#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],xz[4];
long long myd,ans;
void dfs(int x){
    if (x==n+1){
        ans=max(ans,myd);
        return;
    }
    for (int i=1;i<=3;i++){
        if (xz[i]>n/2) return;
        myd+=a[x][i];
        xz[i]++;
        dfs(x+1);
        myd-=a[x][i];
        xz[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for (int k=1;k<=t;k++){
        cin>>n;
        for (int i=1;i<=n;i++){
                for (int j=1;j<=3;j++) cin>>a[i][j];
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
