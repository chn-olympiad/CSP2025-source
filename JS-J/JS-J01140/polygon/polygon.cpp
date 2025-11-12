#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n ;
int ans ;
void dfs(int now, long long cnt, int f)
{
    if(now > n)
    {
        return;
    }
    if(a[now] < cnt && f+1 >= 3)
    {
        ans = (ans+1)%998244353;
    }
    dfs(now+1, cnt + a[now] , f+1);
    dfs(now+1, cnt, f);
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++ )
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i = 1 ; i <= n ; i++ )
    {
        dfs(i+1,a[i],1);
    }
    printf("%lld",ans);
    return 0 ;
}
