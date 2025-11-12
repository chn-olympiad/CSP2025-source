//J00694 at here
#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[114514];
int c[114][514];

bool cmp(const int &x,const int &y)
{
    return x > y;
}

signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >>m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int r = a[1];

    sort(a+1,a+n*m+1,cmp);

    int i = 0,j = 1,cnt = 0;
    for(;;)
    {
        cnt++;
        if(j % 2 == 1)
        {
            i++;
            if(i > n)
            {
                j++;
                i = n;
            }
        }
        else
        {
            //ou
            i--;
            if(i < 1)
            {
                j++;
                i = 1;
            }
        }
        c[i][j] = a[cnt];
        if(j > m) break;
    }

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(c[i][j] == r)
            {
                cout <<j << " " << i;
                return 0;
            }
        }
    }

    cout << "error";
    return 0;
}
/*
feropen
frepoen
froepen
freopne
freepon
freeonp
free on pay
*/
