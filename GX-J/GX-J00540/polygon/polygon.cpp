#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxx;
    cin >> n;
    int a[n + 10];
    int cnt = 0;
    int num = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int k = 2;k >= 0;k--)
    {
        for(int i = 1;i <= n - k;i++)
        {
            maxx = a[i];
            cnt = a[i];
            for(int j = i + 1;j <= n - k + 1;j++)
            {
                cnt += a[j];
                for(int l = 1;l <= n - j;l++)
                {
                    cnt += a[j+l];
                    if(cnt > 2*k)
                    {
                        num++;
                    }
                }

            }
        }
        cout << num;
    }
}

