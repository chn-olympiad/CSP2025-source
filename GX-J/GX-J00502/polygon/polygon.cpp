#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
long long sum[5005],f[5005],ls;
int q(int x,int n,int t)
{
    if(x <= 0) return 0;
    int ans = 0;
    if(t == 1)
    {
        int l =1,r = n;
        while (l <r)
        {

            int mid = (l+r)/2;
            if(a[mid]  >= x)
            {

                r = mid-1;
            }
            else
            {
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
    else{
        for(int i = n; i >= t; i--)
        {
           if(a[i] < x || (ls != 1 && a[i] <= x))
           {

               if(ls == 1)
               {
                   ls = 0;
               }
               ans += q(n-a[i],n-1,t-1);
           }

        }
    }
    return ans;

}
int main()
{
    cin >> n;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i =1; i <= n; i++)
    {

        sum[i] = sum[i-1]+a[i];
    }
    a[1] = 0;
    a[2] = 0;
    for (int i = 3; i <= n; i++)
    {

        if(sum[i] <= 2 * a[i])
        {

            f[i] = f[i-1];
        }
        else
        {
            for(int x = 0; x <= i-3; x++)
            {
                ls = 1;
                f[i] += q(sum[i]-2 * a[i],i-1,x);
            }
            f[i] += f[i-1];
        }
    }
    cout<< f[n] % 998244353;
    return 0;
}
