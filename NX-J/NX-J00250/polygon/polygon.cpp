#include<bits/stdc++.h>
using namespace std;
long long hl[5005];
int main()
{
    freopen("polygon.in", "r",stdin);
    freopen("polygon.out", "w",stdout);
    long long n;
    cin>>n;
    for (long long i=1;i<=n;i++)
    {
        cin>>hl[i];
    }
    if (n<3)
    {
        cout<<0;
        return 0;
    }
    if (n==3)
    {
        sort(hl+1,hl+n+1);
        if (hl[1]+hl[2]>hl[3])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    return 0;
}
