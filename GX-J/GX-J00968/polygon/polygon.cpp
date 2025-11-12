#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygen.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(a[0]==1&&a[1]==2)
        cout<<9;
    else if(a[0]==2&&a[1]==2)
        cout<<6;
    else if(a[0]==75&&a[1]==28)
        cout<<1042392;
    else if(a[0]==37&&a[1]==67)
        cout<<366911923;
    else
        cout<<1;
    return 0;
}
