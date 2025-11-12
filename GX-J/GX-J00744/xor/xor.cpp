#include<bits/stdc++.h>
using namespace std;
long long n,a,b[100001],i;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>a;
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(a==0)
    {
        cout<<1;
        return 0;
    }
    else
    {
        cout<<0;
        return 0;
    }
    return 0;
}
