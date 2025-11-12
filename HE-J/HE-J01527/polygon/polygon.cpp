#include <iostream>
using namespace std;
int n,a[5005],cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n>=3)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n-1;j++)
            {
                for (int x=j+1;x<=n-2;x++)
                {
                    int maxn=max(max(i,j),x);
                    int sum=i+j+x;
                    if (sum>maxn*2)
                    {
                        cnt++;
                    }
                }

            }
        }
        cout<<cnt;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
