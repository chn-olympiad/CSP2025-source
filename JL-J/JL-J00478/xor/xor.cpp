#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen('xor.in','r',stdin);
    freopen('xor.out','w',stdout);
    int m,n;
    cin>>m,n;
    int sum=0;
    int a[500005];
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        sum=sum|a[i];
    }
    cout<<sum;
    return 0;
}
