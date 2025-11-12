#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int p,int q)
{
    return p > q;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1;
    cin >> n >> m;
    int a[n * m + 1];
    for (int x = 1;x <= n * m;x++)
        cin >> a[x];
    a1 = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    int i = 1,j = 1,k,c = 1;
    for (int x = 1;x <= n * m;x++)
        if (a[x] == a1)
            k = x;
    if (c == k)
    {
        cout << i << " " << j;
        return 0;
    }
    for (int x = 1;x <= m;x++)
    {
        if (x % 2 == 1)
            for (int y = 2;y <= n;y++)
            {
                j++;
                c++;
                if (c == k)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        else
            for (int y = n;y >= 2;y--)
            {
                j--;
                c++;
                if (c == k)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        i++;
        c++;
        if (c == k)
        {
            cout << i << " " << j;
            return 0;
        }
    }
    return 0;
}
