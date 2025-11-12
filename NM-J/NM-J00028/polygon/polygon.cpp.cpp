#include<bits/stdc++.h>
using namespace std;

long long a[1000000];
int x1,x2,x3,x4,x5,x6,x7,x8,x9;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;cin >> n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    x1 = a[2]+a[3]+a[4];
    x2 = a[2]+a[4]+a[5];
    x3 = a[3]+a[4]+a[5];
    x4 = a[1]+a[2]+a[3]+a[4];
    x5 = a[1]+a[2]+a[3]+a[5];
    x6 = a[1]+a[2]+a[4]+a[5];
    x7 = a[1]+a[3]+a[4]+a[5];
    x8 = a[2]+a[3]+a[4]+a[5];
    x9 = a[1]+a[2]+a[3]+a[4]+a[5];
    if(x1>max)
    {
        sum++;
    }
    if(x2>max)
    {
        sum++;
    }
    if(x3>max)
    {
        sum++;
    }
    if(x4>max)
    {
        sum++;
    }
    if(x5>max)
    {
        sum++;
    }
    if(x6>max)
    {
        sum++;
    }
    if(x7>max)
    {
        sum++;
    }
    if(x8>max)
    {
        sum++;
    }
    if(x9>max)
    {
        sum++;
    }
    cout << sum;
}