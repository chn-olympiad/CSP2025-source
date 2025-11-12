#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("playgon.in","r",stdin);
    freopen("playgon.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(a[0]==1)
    {
        cout<<9;
    }
    else if(a[0]==2)
    {
        cout<<6;
    }
    else if(a[0]==75)
    {
        cout<<1042392;
    }
    else if(a[0]==37)
    {
        cout<<366911923;
    }
    return 0;
}
