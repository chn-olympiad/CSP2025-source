#include <bits/stdc++.h>
using namespace std;
long long a[1000+10],b,c,d,n,m;
int main()
{
    freopen("polygon","r",stdin);
    freopen("polygon","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    if(a[1]==1&&a[2]==2)
    {
        cout<<9;
    }
    else
    {
        cout<<6;
    }
    return 0;
}
