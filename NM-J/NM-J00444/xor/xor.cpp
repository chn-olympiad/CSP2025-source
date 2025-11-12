#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,sum,num;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==k)
        {
            sum++;
        }
        a[i]=-1;
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]<0)
        {
            num=0;
            continue;
        }

    }
    cout<<sum;
    return 0;
}
