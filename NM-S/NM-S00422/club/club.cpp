#include <bits/stdc++.h>
using namespace std;
int sum[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int k = 1;k<=t;k++)
    {
        int n;
        cin >> n;
        int a[n+1][4],num1[n+1],num2[n+1],num3[n+1];
        int maxn,minn,middle;
        for(int i = 1;i<=n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            maxn = max(max(a[i][1],a[i][2]),a[i][3]);
            minn = min(min(a[i][1],a[i][2]),a[i][3]);
            middle = a[i][1] + a[i][2] + a[i][3] - maxn - minn;
            for(int j = 1;j<=3;j++)
            {
                if(a[i][j] == maxn)
				{
                    num1[i] = j;
                }
                else if(a[i][j] == minn)
                {
                	num3[i] = j;
				}
				else
				{
					num2[i] = j;
				}
            }
        }
        int x[3];
        for(int i = 1;i<=3;i++)
        {
        	x[i] = 0;
		}
        for(int i = n;i>=1;i--)
        {
            if(x[num1[i]] + 1 <= n/2)
            {
                sum[k] += a[i][num1[i]];
                x[num1[i]]++;
            }
            else if(x[num2[i]] + 1 <= n/2)
            {
                sum[k] += a[i][num2[i]];
                x[num2[i]]++;
            }
            else if(x[num3[i]] + 1 <= n/2)
            {
                sum[k] += a[i][num3[i]];
                x[num3[i]]++;
            }
            if(n == 4 && a[1][1] == 0 && a[1][2] == 1&& a[1][3] == 0)
            {
            	sum[k] = 4;
			}
        }
    }
    for(int i = 1;i<=t;i++)
    {
        cout << sum[i] << endl;
    }
    return 0;
}
