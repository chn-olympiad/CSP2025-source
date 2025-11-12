#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int sum=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n>>m;
    int k=m*n;
    for (int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+k+1);
    int num=1;
    for (int i=m;i>=1;i--)
    {

        if (i%2==1)
        {
            for (int j=n;j>=1;j--)
            {

                b[i][j]=a[num];
                num++;
            }
        }
        else
        {
            for (int j=1;j<=n;j++)
            {
                b[i][j]=a[num];
                num++;

            }
        }
    }
    for (int i=m;i>=1;i--)
    {

        if (i%2==1)
        {
            for (int j=n;j>=1;j--)

            {

                if (b[i][j]==p)
                {
                    cout <<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for (int j=1;j<=n;j++)
            {
                if (b[i][j]==p)
                {
                    cout <<i<<" "<<j;
                    return 0;
                }

            }
        }
    }
}
