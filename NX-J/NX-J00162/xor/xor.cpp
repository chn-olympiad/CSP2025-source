#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,l = 0,y = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] == 1)
        {
            y++;
        }
        if(a[i] == 0)
        {
            l++;
        }
    }
    if(k == 0)
    {
        if(y == n)
        {
            if(n == 1)
            {
                cout << 0;
            }
            else if(n % 2 == 0)
            {
                cout << n/2;
            }
            else
            {
                cout << n/2;
            }
        }
        else
        {
            cout << l;
        }
    }
    else
    {
        cout << y;
    }
}
