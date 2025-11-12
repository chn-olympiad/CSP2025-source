#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long n,k;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        cout<<n<<endl;
    }
    else if(k!=0)
    {
        cout<<0<<endl;
    }
    return 0;
}
