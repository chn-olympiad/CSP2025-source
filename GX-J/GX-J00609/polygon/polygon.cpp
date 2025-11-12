#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long x,h=0;
    cin >> x;
    int a[x];
    for(int i=1;i<=x;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+x+1);
    for(int i=1;i<=x;i++)
    {
        h=h+a[x]+a[x-1];
        cout << h;
    }
    return 0;
}
