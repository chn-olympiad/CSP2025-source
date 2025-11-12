#include <bits/stdc++.h>
using namespace std;
int a[1000000],ans,n;
void dfs(int sum,int maxs,int i,int b)
{
    if(sum>2*maxs&&b>2) ans++;
    for(int j=i+1;j<=n;j++)
        dfs(sum+a[j],max(maxs,a[j]),j,b+1);
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(0,0,0,0);
    cout<<ans<<endl;
    return 0;
}
