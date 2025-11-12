#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 105
using namespace std;
typedef long long ll;
int T,N;
int n;
ll a[MAXN][4],ans;
int c[4];
void dfs(int x,ll sum){
    if(c[1]>N||c[2]>N||c[3]>N) return ;
    if(x==n+1){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        c[i]++;
        dfs(x+1,sum+a[x][i]);
        c[i]--;
    }
    return ;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        N=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
