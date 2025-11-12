#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin >> n >> m;
    int f[n + 1][m + 1],cj[n * m],xcj;
    cin >> xcj;
    for (int i = 1;i < n * m;i++)
    {
        cin >> cj[i];
    }
    sort(cj + 1,cj + n * m + 1);
    for (int i = 1;i <= n * m;i++)
    {
        if (cj[i] = xcj)
        {
            if (i % n == 0)
                cout << i / n<< " ";
            else
                cout << i / n + 1 << " ";
            if ((i / n + 1) % n == 1)
                cout << i % n + 1;
            else
                cout << m - i % n + 1;
            break;
        }
    }
    return 0;
}
