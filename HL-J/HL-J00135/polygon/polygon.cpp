#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n;
long long a[1000005],b[1000005];

bool cmp(long long x,long long y)
{
    return x>y;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }

    sort(a+1,a+n+1,cmp);

    for(int i=3;i<=n;i++)
    {
        for(int j=1;i<=n-i+1;j++)
        {
            for(int k=j;k<=i;k++)
            {

            }
            int maxn=-1e8;
            maxn
        }
    }
}
