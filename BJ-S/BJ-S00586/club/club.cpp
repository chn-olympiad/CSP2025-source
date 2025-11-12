#include <bits/stdc++.h>
using namespace std;
long long t,n,a1,b1,c1;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        long long sum = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            long long a,b,c;
            cin >> a >> b >> c;
            if(max(a,max(b,c)) == a)
            {
                if(a1 < n / 2)
                {
                    sum += a;
                    a1++;
                }
                else
                {
                    if(max(b,c) == b && b1 < n/2)
                    {
                        sum += b;
                        b1++;
                    }
                    else
                    {
                        sum += c;
                        c1++;
                    }
                }
            }
            if(max(a,max(b,c)) == b)
            {
                if(b1 < n / 2)
                {
                    sum += b;
                    b1++;
                }
                else
                {
                    if(max(a,c) == a && a1 < n/2)
                    {
                        sum += a;
                        a1++;
                    }
                    else
                    {
                        sum += c;
                        c1++;
                    }
                }
            }
            if(max(a,max(b,c)) == c)
            {
                if(c1 < n / 2)
                {
                    sum += c;
                    c1++;
                }
                else
                {
                    if(max(b,a) == b && b1 < n/2)
                    {
                        sum += b;
                        b1++;
                    }
                    else
                    {
                        sum += a;
                        a1++;
                    }
                }
            }
        }
        cout << sum << endl;
    }
}
