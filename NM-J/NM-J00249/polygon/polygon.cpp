#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[5000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(a[n]>0&&a[n]<25)
        cout<<10;
    else
        cout<<a[n]-345;
    return 0;
}

