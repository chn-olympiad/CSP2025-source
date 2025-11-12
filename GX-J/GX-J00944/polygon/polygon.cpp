#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,a[5001],num=0;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
    cin>>a[i];
       if(a[i] !=a[i+1])
       num++;
    }
    cout<<num;
    return 0;
}
