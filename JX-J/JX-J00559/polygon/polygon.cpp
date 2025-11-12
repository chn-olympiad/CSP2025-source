#include <bits/stdc++.h>
using namespace std;
struct F{
    int z;
    int maxx;
}f[5001][5001];
int n,a[5001];
long long sum=0;
int main()
{
    freopen("polygon.in",r,stdin);
    freopen ("polygon.out",w,stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++)
    {
        f[i][i+2].z=a[i]+a[i+1]+a[i+2];
        f[i][i+2].maxx=a[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=4;j<=n;j++)
        {
            f[i][j].z=f[i][j-1]+a[j];
            f[i][j].maxx=max(f[i][j].maxx,a[j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-j==2||j-i==2)
            {
                if(f[i][j].z>f[i][j].maxx*2)
                {
                    sum++;
                }
            }
        }
    }
    if(sum%2!=0)
    {
        sum=sum/2+1;
    }
    else
    {
        sum/=2;
    }
    if(sum<244)
    {
        cout<<sum;
        return 0;
    }
    else if(sum>244&&sum%353>=244)
    {
        cout<<sum%244;
        return 0;
    }
    else if(sum>353&&sum%998>=353)
    {
        cout<<sum%353;
        return 0;
    }
    else
    {
        cout<<sum%998;
    }
    return 0;
}
