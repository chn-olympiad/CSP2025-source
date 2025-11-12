#include <bits/stdc++.h>
using namespace std;
long long a[1145140];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,num=0;
    cin >>n;
    for(long long i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    for(long long l=1;l<=n;l++)
    {
        for(long long r=l;r<=n;r++)
        {
            long long mx=-1145140,sum=0;
            for(int i=l;i<=r;i++)
            {
                mx=max(mx,a[i]);
                sum+=a[i];
            }
            if(sum>2*mx)
            {
                num++;
                num%=998244353;
            }
        }
    }
    cout <<num;
    return 0;
}
