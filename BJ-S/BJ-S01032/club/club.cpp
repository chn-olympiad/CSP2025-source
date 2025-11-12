#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,a[3][100005],cnt=0,vis[3],maxans=0;
void dfs(int x,int y){
    for(int i=0;i<3;i++)
        if(vis[i]>n/2)
            return;
    if(x>n){
        maxans=max(maxans,cnt);
        return;
    }
    for(int i=0;i<3;i++){
        cnt+=a[y][x];
        vis[y]++;
        dfs(x+1,i);
        vis[y]--;
        cnt-=a[y][x];
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[0][i];
            cin>>a[1][i];
            cin>>a[2][i];
        }
        int maxans2=0;
        for(int i=0;i<3;i++){
            dfs(1,i);
            maxans2=max(maxans2,maxans);
            maxans=0;
            memset(vis,0,sizeof(vis));
        }
        cout<<maxans2<<endl;
        cnt=0;
        maxans=0;
    }
    return 0;
}
