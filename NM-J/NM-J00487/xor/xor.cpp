#include <iostream>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int i = 0;i <= n;i++)
    {
        cin >> a[i];
        if (a[i] - a[i - 1] == k)
        {
            cout << a[i];
        }
        else
        {
            continue;
        }
    }
    return 0;
}
