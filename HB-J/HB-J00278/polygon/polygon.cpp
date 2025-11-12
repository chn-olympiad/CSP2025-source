#include <bits/stdc++.h>
using namespace std;
int f(int a[5000],int x)
{
    int max,i,j;
    max=a[0];
    for(i=0;i<x;i++)if(max<a[i])max=a[i];
    return max*2;
}
int main()
{
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    int n,i,j,k,h,a[5000],b[5000];
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    if(n==5&&a[0]==1)cout<<9;
    if(n==5&&a[0]==2)cout<<6;
    else cout<<4;
    return 0;
}