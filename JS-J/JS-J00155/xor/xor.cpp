#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        if (m==1)
        {
            cnt++;
        }
    }
    if (k==0)
    {
        cout<<n;
    }
    else
    {
        cout<<cnt;
    }
    return 0;
}

