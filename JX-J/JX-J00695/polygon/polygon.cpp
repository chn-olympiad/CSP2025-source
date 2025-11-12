#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int mod = 998244353;
int n,res;
int a[maxn];
bool vis[maxn];
void dfs(int x) {
    if(x>n) {
        int sum=0,End=0,flag=0;
        for(int i=1;i<=n;++i) if(vis[i]) sum+=a[i],End=a[i],flag++;
        if(flag>=3 && sum>End*2)  res=(res+1)%mod;
        return;
    }
    vis[x]=0;
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
    return;
}
int main() {
    freopen("polygon4.in","r",stdin);
    freopen("polygon4.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dfs(1);
    printf("%d\n",res);
    return 0;
}
