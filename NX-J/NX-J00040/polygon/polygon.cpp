#include <bits/stdc++.h>
using namespace std;
int n,a[100005],res;
void dfs(int x,int wz,int sum)
{
    if (x>=3)
    {
        res++;
//        cout<<x<<" "<<wz<<" "<<sum<<endl;
    }
    if (x>=n||wz>=n)
    {
        return ;
    }
    for (int i=wz+1;i<=n;i++)
    {
        if (sum>a[i])
        {
            dfs(x+1,i,sum+a[i]);
        }
        else if (sum==a[i]&&x>=3)
        {
            dfs(x+1,i,sum+a[i]);
        }
        else if(sum==a[i])
        {
            dfs(x,i,sum+a[i]);
        }
        else
        {
            return ;
        }
    }
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            dfs(2,j,a[i]+a[j]);
        }
    }
    cout<<res;
}
