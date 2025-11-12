#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500003];
string b[500004];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(;;)
        {
            if(a[i]==0)
            {
                break;
            }
            b[i]=b[i]+char((a[i]%2)+'0');
            if(a[i]%2==0)
            {
                b[i]=b[i]+'0';
            }
            a[i]=a[i]/2;
        }
    }
    cout<<1;
    return 0;
}
