#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
int sum;
int st=1,en=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            int zhi=a[i];
            int flag=0;
            for (int z=i+1;z<=j;z++)
            {
                zhi=zhi^a[z];
                if (zhi!=k)
                {
                    flag=1;
                }
            }
            if (flag=0)
            {
                if (!(i>=st || j<=en))
                {
                     st=i;
                     en=j;
                     sum++;
                }
            }
        }
    }
    cout<<sum+2;
    return 0;
}
