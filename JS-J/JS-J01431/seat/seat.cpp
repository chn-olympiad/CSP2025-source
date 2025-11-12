#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long  y)
{

    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[1000005];
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++)
    {
        cin >> a[i];
    }
    long long r = a[1];
    sort(a + 1,a + 1 + n * m,cmp);
    long long num;
    for(int i = 1;i <= n * m;i ++)
    {

        if(a[i] == r)
        {

            num = i;
            break;
        }
    }
    if(num % n == 0)
    {
            long long l = num / n;
            if(l % 2 == 1)
            {
                cout <<  l << ' ' << m;
            }
            else
            {
                cout << l << ' ' << 1;
            }
    }
    else
    {
        long long l = num / n;
        if(l % 2 == 0)
        {
            long long c = l;
            cout << c + 1 << ' ' << (num % n);
        }
        else
        {
            cout << l  + 1 << ' ' << n - (num % n) + 1;
        }
    }
    return 0;
}
