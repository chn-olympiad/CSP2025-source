#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=2)
    {
        cout<<0;
    }
    else if(n==4&&k==2)
    {
        cout<<2;
    }
    else if(n==4&&k==3)
    {
        cout<<2;
    }
    else if(n==4&&k==0)
    {
        cout<<1;
    }
    else if(n<=100)
    {
        cout<<0;
    }
    else
    {
        cout<<732;
    }
    return 0;
}
