#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef pair<int,int> PII;
int n,m;
int a[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int sum = n * m;
    for (int i = 1;i <= sum;i ++)
    {
        cin >> a[i];
    }
    int lm = a[1];
    int lmi = 0;
    sort(a + 1,a + 1 + sum);
    int o = 1;
    for (int i = sum;i >= 1 ;i --)
    {
        //cout << a[i] << "**" << endl;
        if (a[i] == lm)
        {
            lmi = o;
        }
        o ++;
    }
    //cout << lmi << endl;
    int dy[] = {1,-1};
    int x = 1,y = 1;
    int i = 0,pi = 1;
    while (pi <= lmi)
    {
        if (i % 2 == 0)
        {
            while(y < m)
            {
                y += dy[i];
                pi ++;
                if (pi == lmi)
                {
                    cout << x << ' ' << y;
                    return 0;
                }
            }
            x += 1;
            pi ++;
            if (pi == lmi)
            {
                cout << x << ' ' << y;
                return 0;
            }
            i  = (i + 1) % 2;
        }
        else
        {
            while(y > 1)
            {
                y += dy[i];
                pi ++;
                if (pi == lmi)
                {
                    cout << x << ' ' << y;
                    return 0;
                }
            }
            x += 1;
            pi ++;
            if (pi == lmi)
            {
                cout << x << ' ' << y;
                return 0;
            }
            i = (i + 1) % 2;
        }
    }
    return 0;
}
