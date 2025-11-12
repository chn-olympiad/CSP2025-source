#include <iostream>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i <= n;i++)
    {
        cin >> a[i];
        if (a[i] > n)
        {
            cout << a[i];
            break;
        }
        else
        {
            cout << n;
        }
    }
    return 0;
}
