#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200005];
int maxans;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k%2 == 0)
        int fla = 0;
    else
        int fla = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            int num = 0, ans = 0;
            for (int j = i; j <= n; j++)
            {
                if (a[j]!=1)
                {
                    break;
                }
                num++;
            }
            if (num % 2 == 0)
                if (fla == 0)
                    maxans+=num;
            else
                if (fla == 1)
                    maxans+= num;
            for (int j = i; j <= n; j++)
                ans++;
                if (ans % 2 == 0&&fla == 0)
                    maxans++;
                if (ans % 2 == 1 && fla == 1)
                    maxans++;
        if (a[i] == 0)
            if (fla == 0)
                for (int j = i; j <= n; j++)
                {
                    if (a[j]!=0)
                    {
                        break;
                    }
                }
                for (int j = i; j <= n; j++)
                    ans++;
                    if (ans % 2 == 0&&fla == 0)
                        maxans++;
                    if (ans % 2 == 1 && fla == 1)
                        maxans++;
                maxans++;
            }
    }
    cout << maxans;
    return 0;
}
