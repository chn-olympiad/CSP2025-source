#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3],cnt[4],n;
int dfs(int u,int ans){
    if(u>n){
        return ans;
    }
    int mx=INT_MIN;
    for(int i=1;i<=3;i++){
        if(cnt[i]<(n/2)){
            cnt[i]++;
            mx=max(mx,dfs(u+1,ans+a[u][i]));
            cnt[i]--;
        }
    }
    return mx;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        n=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        cout<<dfs(1,0)<<endl;
    }
    return 0;
}
