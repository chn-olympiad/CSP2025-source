#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,r[500005];
    cin>>n>>k;
    int sum=0,sumq=0;
    if (n=0)
    {
        for (int i=1;i<=n;i++)
        {
            cin>>r[i];
            if (r[i]=0)
            {
                sum++;
            }
        }
        cout<<sum;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            int sum1=0;
            sumq+=r[j];
            if (sumq>k)
            {
                sumq=0;
            }
            if (sumq=k)
            {
                sum++;
                sumq=0;
            }
        }
        sum=max(sum,sum1);
    }
    cout<<sum;
    return 0;
}
