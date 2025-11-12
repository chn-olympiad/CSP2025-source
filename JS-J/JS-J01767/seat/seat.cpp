#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],r,i,h,l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(long long i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    r = a[1];
    sort(a+1,a+n*m+1,greater<long long>());
    i = 1;
    for( ;i <= n*m;i++)
    {
        if(a[i] == r) break;
    }
    l = (i+n-1)/n;
    if(l&1)
    {
        h = i-(l-1)*n;
    }
    else
    {
        h = l*n-i+1;
    }
    cout << l << " " << h;
    return 0;
}
