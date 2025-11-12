#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5,mod=998244353;
int n,a[N],mx,ans=0;
void dfs(int i,int sum,int mx){
    if(i==n+1){
        if(sum>mx*2)
            ans=(ans+1)%mod;
        return;
    }
    dfs(i+1,sum+a[i],max(mx,a[i]));
    dfs(i+1,sum,mx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n==3){
        if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])
            puts("1");
        else
            puts("0");
        return 0;
    }
    dfs(1,0,0);
    printf("%d",ans);
    return 0;
}
