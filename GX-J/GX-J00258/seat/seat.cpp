#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n*m+2],ans[n+2][m+2];
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1);
    for (int i=1;i<=n*m;i++)
    {
        if (n%2==1)
            for (int k=m;k>=1;k--)
            {
                a[i]=ans[i][k];
                if (ans[i][k]==x)
                    cout<<ans[i][k];
                    break;
            }

        else
            for (int j=1;j<=m;j++)
            {
                a[i]=ans[i][j];
                if (ans[i][j]==x)
                    cout<<ans[i][j];
                    break;
            }
    }
    return 0;
}
