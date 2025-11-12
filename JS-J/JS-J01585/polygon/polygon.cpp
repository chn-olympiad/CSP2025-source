#include<bits/stdc++.h>
using namespace std;
int a[502];
int n;
long long ans;
const int mod = 998244353;
inline void dfs(int x,int cnt,int sum){
    if(x > n) return ;
    dfs(x+1,cnt,sum);
    if(cnt >= 2 && sum > a[x]){
        ans++;
        ans %= mod;
    }
    dfs(x+1,cnt+1,sum+a[x]);

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dfs(1,0,0);
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
