#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10000],n,sum=0;
    cin>>n;//for task 1 to 3
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==3)
    {
        sort(a+1,a+4);
        if(a[1]+a[2]<=a[3])cout<<0;
        else cout<<1;
        return 0;
    }
    else //for task 15 to 20
    {
        for(int i=3;i<=n;i++)sum=(sum+i*(n-i+1))%998244353;
    }

    return 0;
}
