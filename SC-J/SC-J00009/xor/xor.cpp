#include <iostream>
#include <cstdio>
using namespace std;

int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >>n >>k;
    if (k == 0)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >>a[i];
            if (a[i - 1] == a[i] && a[i] == 1) cnt++;
            else if (a[i] == 0) cnt++;
        }
        cout <<cnt;
    }
    else
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >>x;
            if (x == 1) cnt++;
        }
        cout <<cnt;
    }
    return 0;
}
