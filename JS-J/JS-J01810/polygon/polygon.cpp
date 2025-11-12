#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
long long x;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
    {
        cout<<0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++)
    {
        for(int j=2;j<=i-1;j++)
        {
            for(int sa=1;sa<=i-2;sa++)
            {
                x=a[sa];
                for(int k=sa+1;k<=i-1;k++)
                {
                    if(k!=j)
                        x+=a[k];
                    if(x>a[i])
                    {
                        sum++;
                        sum%=998244353;
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
