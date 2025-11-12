#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long b=0;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    b=b+a[i];
    }
    cout<<b%998244353;
}
