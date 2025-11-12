#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("numder.in""r"stdin)
    freopen("numder.out""w"stdout)
    int n;
    for(int i=1;i<=m;i++)
    {
       cin>>n[i];
    }
    if(n[i]>n[i+1])
    {
       n[i]=n[i+1];
       n[i+1]=n[i];
    }
    cout<<n[i];
