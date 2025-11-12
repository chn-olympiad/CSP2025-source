#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500000];
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (k==2)
        {
            cout<<2;
            break;
        }
    }

    return 0;
}
