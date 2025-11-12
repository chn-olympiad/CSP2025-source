#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],sum=0;
long long f[500010][500010];
int main()
{
    freopen("xor.in",r,stdin);
    freopen("xor.out",w,stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i][i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            f[i][j]=f[i][j-1]+a[j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(f[i][j]==k)
            {
                sum++;
            }
        }
    }
    if(sum%2!=0)
    {
        cout<<sum/2+1;
    }
    else
    {
        cout<<sum/2;
    }
    return 0;
}
