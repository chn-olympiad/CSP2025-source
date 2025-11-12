#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    int tmp=a[1];
    for (int i=1;i<n*m;i++)
    {
        for (int j=1;j<=n*m-i;j++)
        {
            if (a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
//    for (int i=1;i<=n*m;i++)
//    {
//        cout << a[i]<< endl;
//    }
    int loc;
    for (int i=1;i<=m*n;i++)
    {
        if (a[i]==tmp)
        {
            loc=i;
            break;
        }
    }
    int l=1;
    for (int i=1;i<=m;i++)
    {
        if (i%2!=0)
        {
            for (int j=1;j<=n;j++)
            {
                if (l==loc)
                {
                    cout << i << ' '<< j;
                    break;
                }
                l++;
            }
        }
        else
        {
            for (int j=n;j>=1;j--)
            {
                if (l==loc)
                {
                    cout << i <<' '<< j;
                    break;
                }
                l++;
            }
        }
    }
    return 0;
}
