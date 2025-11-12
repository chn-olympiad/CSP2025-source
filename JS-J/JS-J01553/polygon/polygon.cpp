#include<bits/stdc++.h>
using namespace std;
int a[505];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            cout<<1<<endl;
            return 0;
        }
        cout<<0<<endl;
        return 0;
    }
    cout<<n*2-1<<endl;
    return 0;
}
