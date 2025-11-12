#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],z = 0;
bool b[100005];
long long h = 998244353;
bool jc()
{
    long long t = 0,maxx = -1,s = 0;
    for(int i = 1; i <= n; i++)
    {
        if(b[i] == 1)
        {
            s++;
            t += a[i];
            maxx = max(maxx,a[i]);
        }
    }

    if(maxx*2 < t && s >= 3)return 1;
    return 0;
}
void xuan(long long xian)
{
    if(xian <= n)
    {
        b[xian] = 1;
        xuan(xian+1);
        b[xian] = 0;
        xuan(xian+1);

    }
    else
    {
        if(jc() == 1)z++;
        z = z % h;
        return;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    xuan(0);
    cout << z/2;
    return 0;
}
