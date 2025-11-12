#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int d[10][10];
int main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    cin >> n >> m;
    for (int i=0;i<n*m;++i)
    {
        cin >> a[i];
    }
    int b=a[1];
    sort(a,a+n*m);
    int k=0;
    for (int i=m;i>=1;--i)
    {
        if(i%2==0)
        {
            for(int j=1;j<=n;++j)
            {
                k++;
                d[i][j]=a[k];
                if(d[i][j]==b)
                {
                    cout << j << " " << i;
                    break;
                }

            }
        }
        else
        {
            for(int j=n;j>=1;--j)
            {
                k++;
                d[i][j]=a[k];
                if(d[i][j]==b)
                {
                    cout << j << " " << i;
                    break;
                }

            }
        }
        return 0;
    }
}
