#include <bits/stdc++.h>
using namespace std;
int n,a[500005],k,num,b[260];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=255;i++)
    {
        num=max(num,b[i]);
    }
    cout<<num;
    return 0;
}
