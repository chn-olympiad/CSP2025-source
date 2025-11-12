#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,sum=0,maxn;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if (n<=500)
    {
        for (int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for (int i=1;i<=n-2;i++)
            for (int j=i+2;j<=n;j++)
            {
                sum=0;
                for (int k=i;k<=j;k++)
                    sum+=a[k];
                maxn=a[j];
                if (sum > 2*maxn)
                {
                    ans++;
                }
            }
        cout<<ans;
    }
    else
    {
        cout<<99890;
    }
    return 0;
}
