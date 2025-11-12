#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in",'r',stdin);
    freopen("xor.out",'w',stdout);
    long long k,a[500001],b,c,e;
    cin>>b>>k;
    for(long long i=1;i<=b;i++)
    {
        cin>>a[i];
    }
    c=1;e=0;
    for(long long i=1;i<=b;i++)
    {
        int d=0;
        for(int j=c;j<=i;j++)
        {
            d^=a[j];
        }
        if(d==k)
        {
        c=i+1;e++;
        }
    }
    cout<<e;
}
