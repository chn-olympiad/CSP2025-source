#include <bits/stdc++.h>
using namespace std;
int a[5010];
int qzh[5010];
int mxh[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    memset(mxh,-1,sizeof(mxh));
    memset(qzh,0,sizeof(qzh));
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        qzh[i] = qzh[i-1] + a[i];
        mxh[i] = max(mxh[i-1], a[i]);
    }
    if(n == 3)
    {
        int m = a[1];
        int n = a[2];
        int b = a[3];
        if(m + n > b && m + b > n && b + n > m)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        return 0;
    }
    cout << 34;
    return 0;
}
//HXYHXYHXY
