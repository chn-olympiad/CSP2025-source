#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
const int N = 1e5 + 10;
int a[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++) cin >> a[i];
    int b = a[1],k;
    sort(a + 1,a + n * m + 1,cmp);
    for(int i = 1;i <= n * m;i ++)
    {
        if(a[i] == b)
        {
            k = i;
            break;
        }
    }
    int c,r;
    if(n * (k / n) == k) c = k % n + 1;
    else c = k / n + 1;
    if(c % 2 == 0)
    {
        if(k % n == 0) r = 1;
        else r = n - k % n + 1;
    }
    else
    {
        if(k % n == 0) r = n;
        else r = k % n;
    }
    cout << c << " " << r;
    return 0;
}
