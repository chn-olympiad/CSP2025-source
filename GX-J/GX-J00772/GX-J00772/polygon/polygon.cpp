#include <algorithm>
#include <iostream>
using namespace std;
const int md=998244353;
int a[5007],cnt=0,n;
void dfs(int he,int mxxb)
{
    if(mxxb<=n)
        for(int i=mxxb+1;i<=n;++i)
        {
            if(a[i]<he)cnt=(cnt+1)%md;
            dfs(he+a[i],i);
        }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;++i)for(int j=i+1;j<=n-1;++j)dfs(a[i]+a[j],j);
    cout<<cnt;
    return 0;
}
