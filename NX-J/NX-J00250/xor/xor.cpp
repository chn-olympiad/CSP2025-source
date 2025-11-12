#include<bits/stdc++.h>
using namespace std;
long long sh[500005];
int main()
{
    freopen("xor.in", "r",stdin);
    freopen("xor.out", "w",stdout);
    long long n,k;
    cin>>n>>k;
    bool b=1,c=1;
    for (long long i=1;i<=n;i++)
    {
        cin>>sh[i];
        if (sh[i]!=1 && b==1)
        {
            b=0;
        }
    }
    if (b==1)
    {
        if (k==0)
        {
            cout<<n;
            return 0;
        }
    }
    return 0;
}

