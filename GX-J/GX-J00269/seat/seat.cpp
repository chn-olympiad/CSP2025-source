#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1999];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n>>m;

    for(int i = 1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    int c = a[1],sum = 1;
    for(int i = 2;i<=n*m;i++)
    {
        if(c < a[i])
        {
            sum++;
        }
    }
    int h=0,l=1;
    for(int i = 1;i<=sum;i++)
    {
        if(l%2 == 1)
        {
            h++;
            if(i != sum)
            {
                if(h == n)
                {
                    l++;
                    i++;
                }
            }
        }
        else if(l%2 == 0)
        {
            h--;
            if(i != sum)
            {
                if(h == 1)
                {
                    l++;
                    i++;
                }
            }
        }
    }
    cout << l<<" " << h;
    return 0;
}
