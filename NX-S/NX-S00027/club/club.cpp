#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t >> n;
    int q = n/2;
    while(t--)
    {
        int anss = 0;
        int a[100005] = {},ans[100005] = {};
        int num1 = 0,num2 = 0,num3 = 0,f = 0;
        while(n--)
        {
            for (int i = 1;i <= 3;i++)
            {
                cin >> a[i];
            }
            int yi = a[1],er = a[2],sa = a[3];
            sort(a+1,a+3+1);
            if (a[3] == yi)
            {
                ans[1]++;
                num1++;
            }
            if (a[3] == er)
            {
                ans[2]++;
                num2++;
            }
            if (a[3] == sa)
            {
                ans[3]++;
                num3++;
            }
        }
        int yii = ans[1],err = ans[2],saa = ans[3];
        sort(ans+1,ans+3+1);
        if (ans[3] == yii)
        {
            if (num1 <= q)
            {
                anss += yii * num1;
                f += num1;
            }
            else
            {
                anss += yii * q;
                f += q;
            }
        }
        if (ans[3] == err)
        {
            if (num2 <= q)
            {
                anss += err * num2;
                f += num2;
            }
            else
            {
                anss += yii * q;
                f += q;
            }
        }
        if (ans[3] == saa)
        {
            if (num3 <= q)
            {
                anss += saa * num3;
                f += num3;
            }
            else
            {
                anss += saa * q;
                f += q;
            }
        }
        cout << ans;
    }
    return 0;
}
