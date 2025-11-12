//GZ-S00018 伍珈呈 贵州师范大学云岩实验中学
#include <bits/stdc++.h>
using namespace std;
int a[100005][4];
int vis[4],n;
long long dfs(int c,long long ans){
    if(c==n+1){return ans;}
    long long tmp=0;
    for(int i=1;i<=3;i++){
        if(vis[i]>=n/2){continue;}
        vis[i]++;
        tmp=max(tmp,dfs(c+1,ans+a[c][i]));
        vis[i]--;
    }
    return tmp;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        cout<<dfs(1,0)<<endl;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
