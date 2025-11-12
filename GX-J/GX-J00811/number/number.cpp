#include<bits/stdc++.h>
using namespace std;
string a;
long long j;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    long long b = a.length();
    long long c[b + 5];
    for(int i = 0; i < b; i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            c[j] = int(a[i]) - 48;
            j++;
        }
    }
    for(int i = 0; i < j; i++)
    {
        int n = 0;
        int x = 0;
        for(int q = 0; q < j; q++)
        {
            if(c[q] != 10)
            {
                n = c[q];
                break;
            }
        }
        for(int q = 0; q < j; q++)
        {
            if(c[q] != 10)
            {
                if(n < c[q])
                {
                    n = c[q];
                    x = q;
                }
            }
        }
        cout<<n;
        c[x] = 10;
    }
    return 0;
}
