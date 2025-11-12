#include<bits/stdc++.h>
using namespace std;
int a[5005];
int sum[5005][5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    sum[0][1]=0;
    sum[0][2]=0;
    sum[1][1]=a[1];
    sum[1][2]=a[1];
    for(int i=2;i<=n;i++)
    {
        sum[i][1]=a[i]+sum[i-1][1];
        sum[i][2]=max(a[i],sum[i-1][2]);
    }
    int ans=0;
    for(int i=0;i<=n-3;i++)
    {
        for(int j=i+3;j<=n;j++)
        {
            if(sum[j][1]-sum[i][1] > 2*max(sum[j][2],sum[i][2]))
                ans++;
        }
    }
    cout<<ans;
    return 0;
}