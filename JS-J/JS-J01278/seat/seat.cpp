#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,k,x,a[1010];
    cin >> n >> m;
    for(long long i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    k = a[1];
    sort(a+1,a+n*m+1);
    for(long long i = 1;i <= n*m;i++)
    {
        if(a[i]==k)
        {
            k = n*m-i+1;
            break;
        }
    }

    x = ceil(k*1.0/n);
    cout << x << " ";
    if(x&1)
    {
        if(k%n!=0)cout << k%n;
        else cout << n;
    }
    else
    {
        if(k%n!=0)cout << n-(k%n)+1;
        else cout << 1;
    }
    return 0;
}
