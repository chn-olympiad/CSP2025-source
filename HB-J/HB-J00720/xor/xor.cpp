#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005],b[100005],idx,ans1=-1;
bool c[46332][46332];
void dfs(int i)
{
    if(i>n)
    {
        ans1=max(ans1,idx);
        idx=0;
        return;
    }
    for(int j=1;j<=n-i+1;j++)
    {
        if(i<=46332&&j<=46332)
            if(c[i][j]==1) continue;
        int ans=a[i];
        for(int j1=i+1;j1<=i+j-1;j1++)
        {
            ans^=a[j1];
        }
        if(ans==k)
        {
            b[++idx]=j;
            dfs(i+j);
        }else if(i<=46332&&j<=46332)
        {
            c[i][j]=1;
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    cout<<ans1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
