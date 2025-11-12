#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.in","r",stdin);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            f=0;
        }
    }
    if(f)
    {
        cout<<n;
    }
    return 0;
}
