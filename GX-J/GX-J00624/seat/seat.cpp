#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    if (a>=b)
    {
        return b<=a;
    }
    else
    {
        return a>b;
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[1000],s,l=1,k=0;
    cin >> n >> m;
    for (int i=0;i<n*m;i++)
    {
        cin >> a[i];
    }
    s=a[0];
    sort(a,a+n*m,cmp);
    for (int i=0;i<n*m;i++)
    {
        k++;
        if (k>n)
        {
            l++;
            k=1;
        }
        if (a[i]==s)
        {
            if (l%2!=0)
            {
                k=k;
            }
            else
            {
                k=n-k;
            }
            cout << l << " " << k;
        }
    }
    return 0;
}
