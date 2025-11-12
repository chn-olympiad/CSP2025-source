#include<bits/stdc++.h>
using namespace std;

int m,n,a[105];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);


    cin>>n>>m;

    for(int i = 1;i <= n*m;i++) cin>>a[i];

    int f = a[1];

    sort(a + 1,a + n*m + 1);

    for(int i = n*m,k = 1,l = 1;i >= 1;i--,k++)
    {
        if(k == n+1)
        {
            k = 1;
            l++;
        }

        if(a[i] == f)
        {
            if(l % 2 == 1)
            {
                cout<<l<<' '<<k;
                return 0;
            }

            else
            {
                cout<<l<<' '<<n-k+1;
                return 0;
            }
        }

    }

    return 0;
}
