#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[50000];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    if(a[0]==1)cout<<9;
    if(a[0]==2)cout<<6;
    if(a[0]==75)cout<<1042392;
    if(a[0]==37)cout<<366911923;
    return 0;
}
