#include<bits/stdc++.h>
using namespace std;
int n,a[5010],Max=0,sum=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        Max=max(Max,a[i]);
        Sum+=a[i];
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        if(sum>Max*2)
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
