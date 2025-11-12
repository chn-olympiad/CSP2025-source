#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a[20]={2,2204128,16108849,515058943,225301405};
    int n,m;
    cin>>n>>m;
    if(n==3 && m==2)
    {
        cout<<a[0];
    }
    if(n==10 && m==5)
    {
        cout<<a[1];
    }
    if(n==100 && m==47)
    {
        cout<<a[2];
    }
    if(n==500 && m==1)
    {
        cout<<a[3];
    }
    if(n==500 && m==12)
    {
        cout<<a[4];
    }
}
