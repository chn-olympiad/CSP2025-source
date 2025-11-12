#include<bits/stdc++.h>
using namespace std;
int n,a[3005],cnt;
void dfs(int k,int pre,int maxn,int sum)
{

    if(k>=4)
        if(sum>2*maxn)
            cnt++;
    if(k>=n+1||pre==n)
        return;
    for(int i=pre+1;i<=n;i++)
        dfs(k+1,i,max(maxn,a[i]),sum+a[i]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,0,0);
    cout<<cnt;
    return 0;
}
