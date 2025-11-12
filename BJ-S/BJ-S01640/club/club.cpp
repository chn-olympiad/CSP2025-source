#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int a[N][5],team[5];
int ans=-1;

void dfs(int x,int n,int sum){
    if(x==n+1){
        if(team[1]<=n/2&&team[2]<=n/2&&team[3]<=n/2){
            ans=max(ans,sum);
        }
        return;
    }
    for(int i=1;i<=3;i++){
        team[i]++;
        dfs(x+1,n,sum+a[x][i]);
        team[i]--;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        memset(team,0,sizeof(team));
        ans=-1;
        dfs(1,n,0);
        cout<<ans<<endl;
    }
    return 0;
}
//t1
