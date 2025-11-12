#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,m=0;
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        long long a;
        cin>>a;
        if(a==k)m++;
    }
    cout<<m;
    return 0;
}
