#include<bits/stdc++.h>
using namespace std;


int t,n,a[100001][5],p[5];
long long ans,sum;
void dfs(int k){
    ans=max(ans,sum);
    if(k>n)return;
    for(int i=1;i<=3;i++){
        if(p[i]<n/2){
            p[i]++;
            sum+=a[k][i];
            dfs(k+1);
            p[i]--;
            sum-=a[k][i];
        }
    }
}

void solve(){
    sum=0;ans=0;
    memset(p,0,sizeof(p));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    printf("%lld\n",ans);
}


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
