#include <iostream>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num = 0;
    int a[10005]={};
    int e[10005]={};
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        e[i] = -1;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = i;j <= n;j++)
        {
            int b = 0;
            for (int h = i;h <= j;h++)
            {
                for (int t = 1;t <= n;t++)
                {
                    if (a[h] == e[t])
                    {
                        b = -1;
                        break;
                    }
                }
                b += a[h];
            }
            if (b == k)
            {
                num++;
                for (int h = i;h <= j;h++)
                {
                    e[h] = a[h];
                }
            }
        }
    }
    cout << num;
    return 0;
}
