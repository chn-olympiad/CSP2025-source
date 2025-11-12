#include <iostream>
using namespace std;
int n, k, a[500005],b[500005], num1 = 0, num2 = 0;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {

        cin >> a[i];
        b[i] = 0;
    }
    if(k == 0)
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 1)
                num1++;
            if(a[i] == 0)
                num2++;
        }
        cout << max(num1 / 2, num2);
    }
    else if(k == 1)
    {
        for(int i = 2; i <= n; i++)
        {
            if(a[i] == 1)
                if(a[i - 1] == 0 && b[i] == 0 && b[i - 1] == 0)
                {
                    b[i] = 1;
                    b[i - 1] = 1;
                    num1++;
                }
            if(a[i] == 0)
            {
                if(a[i - 1] == 1 && b[i] == 0 && b[i - 1] == 0)
                {
                    b[i] = 1;
                    b[i - 1] = 1;
                    num1++;
                }
            }
        }
        cout << num1;
    }
    return 0;
}
