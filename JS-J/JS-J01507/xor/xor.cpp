#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int fun(int l;,int r)
{
    int ans=a[l];
    for(int i=l+1;i<=r;i++)
    {
        ans=ans||a[i];
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int x=fun(i,j);
            if(x==k)
                sum++;
        }
    }
    cout<<sum;

    return 0;
}