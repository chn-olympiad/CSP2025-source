#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n,max = 0,sum = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            max  = 0;
            if(a[j] > max)
            {
                max = a[j];
            }
            sum += a[i];
        }
        if (sum - max > max * 2)
        {
            cnt++;
        }
    }
    cout << cnt * 3;
	return 0;
}

