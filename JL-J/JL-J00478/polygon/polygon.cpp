#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen('polygon.in','r',stdin);
    freopen('polygon.out','w',stdout);
    int n,sum=0;
    cin>>n;
    int a[5005];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sum=(1+n)*n/2;
    cout<<sum-6;
    return 0;
}
