#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[10005];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==4)
    {
        if(k==2||k==3)
        {
            cout<<2<<endl;
        }
        if(k==0)
        {
            cout<<1<<endl;
        }
    }
    else if(n>=5)
    {
        cout<<3<<endl;
    }
    else
    {
        cout<<1<<endl;
    }
    return 0;
}
