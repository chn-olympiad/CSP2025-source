#include <iostream>
#include <stdio.h>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
#define MAXN 100003
int a[MAXN][5],cnt[5],n,maxn;
void dfs(int x,int sum){
    if(x>n){
        maxn=std::max(maxn,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]>=n/2) continue;
        cnt[i]++;
        dfs(x+1,sum+a[x][i]);
        cnt[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        maxn=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)   cin>>a[i][j];
        dfs(1,0);
        cout<<maxn<<endl;
    }
    return 0;
}
